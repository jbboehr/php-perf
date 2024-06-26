#!/usr/bin/env php
<?php

// ok, these aren't all examples per se
// this one tries to estimate the overhead of calling Perfidious\Handle::read()

use function Perfidious\open;

$rest_index = null;
$opts = getopt('', [
    'verbose',
    'count:',
], $rest_index);
$pos_args = array_slice($argv, $rest_index);

if (count($pos_args) <= 0) {
    $pos_args = [
        'perf::PERF_COUNT_HW_CPU_CYCLES:u',
        'perf::PERF_COUNT_HW_INSTRUCTIONS:u',
    ];
}

$count = $opts['count'] ?? 10000;

$handle = open($pos_args);
$handle->enable();

$stats = [];

gc_collect_cycles();
gc_disable();

for ($i = 0; $i < $count; $i++) {
    $handle->reset();
    $left = $handle->readArray();
    $right = $handle->readArray();
    foreach ($left as $k => $lv) {
        $rv = $right[$k];
        $delta = abs($lv - $rv);
        if (array_key_exists('verbose', $opts)) {
            printf("%s: left=%d right=%d delta=%d\n", $k, $lv, $rv, $delta);
        }
        $stats[$k][] = $delta;
    }
    usleep(100);
}

foreach ($stats as $k => $data) {
    $variance = variance($data);
    $mean = mean($data);
    $stddev = stddev($data);
    $min = min($data);
    $max = max($data);
    printf(
        "%s\n  samples=%d\n  mean=%g\n  variance=%g\n  stddev=%g\n  min=%g\n  max=%g\n",
        $k,
        count($data),
        $mean,
        $variance,
        $stddev,
        $min,
        $max
    );
}

/**
 * @see https://github.com/phpbench/phpbench/blob/master/lib/Math/Statistics.php
 * @license https://github.com/phpbench/phpbench/blob/master/LICENSE
 */

/**
 * @param list<int|float> $values
 */
function variance(array $values, bool $sample = false): int|float
{
    $average = mean($values);
    $sum = 0;

    foreach ($values as $value) {
        $diff = ($value - $average) ** 2;
        $sum += $diff;
    }

    if (count($values) === 0) {
        return 0;
    }

    $variance = $sum / (count($values) - ($sample ? 1 : 0));

    return $variance;
}

/**
 * @param list<int|float> $values
 */
function stddev(array $values, bool $sample = false): float
{
    $variance = variance($values, $sample);

    return \sqrt($variance);
}

/**
 * @param list<int|float> $values
 */
function mean(array $values): int|float
{
    if (empty($values)) {
        return 0;
    }

    $sum = array_sum($values);

    if (0 == $sum) {
        return 0;
    }

    $count = count($values);

    return $sum / $count;
}

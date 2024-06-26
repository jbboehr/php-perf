--TEST--
Perfidious\Handle (open fails with missing cap)
--EXTENSIONS--
perfidious
--SKIPIF--
<?php if (get_current_user() === 'root') die("skip: would fail as root"); ?>
<?php if (Perfidious\DEBUG) die("skip: must not be compiled in debug mode"); ?>
--FILE--
<?php
// Note: this test will fail if run with CAP_PERFMON (e.g. as root)
$rv = Perfidious\open([
    "perf::PERF_COUNT_SW_CPU_CLOCK:u",
], pid: 1);
--EXPECTF--
%A Uncaught Perfidious\IOException: pid greater than zero and CAP_PERFMON %A
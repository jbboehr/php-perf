/**
 * Copyright (C) 2024 John Boehr & contributors
 *
 * This file is part of php-perf.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <perfmon/pfmlib.h>
#include "Zend/zend_API.h"
#include "Zend/zend_enum.h"
#include "php_perf.h"

PERF_PUBLIC zend_class_entry *perf_pmu_enum_ce;

static zend_class_entry *register_class_PmuEnum(void)
{
    zend_class_entry *class_entry = zend_register_internal_enum("PerfExt\\PmuEnum", IS_LONG, NULL);
    zval tmp = {0};

#define D(e)                                                                                                           \
    do {                                                                                                               \
        ZVAL_LONG(&tmp, (zend_long) e);                                                                                \
        zend_enum_add_case_cstr(class_entry, #e, &tmp);                                                                \
    } while (false);

    D(PFM_PMU_NONE);
    D(PFM_PMU_GEN_IA64);
    D(PFM_PMU_ITANIUM);
    D(PFM_PMU_ITANIUM2);
    D(PFM_PMU_MONTECITO);
    D(PFM_PMU_AMD64);
    D(PFM_PMU_I386_P6);
    D(PFM_PMU_INTEL_NETBURST);
    D(PFM_PMU_INTEL_NETBURST_P);
    D(PFM_PMU_COREDUO);
    D(PFM_PMU_I386_PM);
    D(PFM_PMU_INTEL_CORE);
    D(PFM_PMU_INTEL_PPRO);
    D(PFM_PMU_INTEL_PII);
    D(PFM_PMU_INTEL_ATOM);
    D(PFM_PMU_INTEL_NHM);
    D(PFM_PMU_INTEL_NHM_EX);
    D(PFM_PMU_INTEL_NHM_UNC);
    D(PFM_PMU_INTEL_X86_ARCH);

    D(PFM_PMU_MIPS_20KC);
    D(PFM_PMU_MIPS_24K);
    D(PFM_PMU_MIPS_25KF);
    D(PFM_PMU_MIPS_34K);
    D(PFM_PMU_MIPS_5KC);
    D(PFM_PMU_MIPS_74K);
    D(PFM_PMU_MIPS_R10000);
    D(PFM_PMU_MIPS_R12000);
    D(PFM_PMU_MIPS_RM7000);
    D(PFM_PMU_MIPS_RM9000);
    D(PFM_PMU_MIPS_SB1);
    D(PFM_PMU_MIPS_VR5432);
    D(PFM_PMU_MIPS_VR5500);
    D(PFM_PMU_MIPS_ICE9A);
    D(PFM_PMU_MIPS_ICE9B);
    D(PFM_PMU_POWERPC);
    D(PFM_PMU_CELL);

    D(PFM_PMU_SPARC_ULTRA12);
    D(PFM_PMU_SPARC_ULTRA3);
    D(PFM_PMU_SPARC_ULTRA3I);
    D(PFM_PMU_SPARC_ULTRA3PLUS);
    D(PFM_PMU_SPARC_ULTRA4PLUS);
    D(PFM_PMU_SPARC_NIAGARA1);
    D(PFM_PMU_SPARC_NIAGARA2);

    D(PFM_PMU_PPC970);
    D(PFM_PMU_PPC970MP);
    D(PFM_PMU_POWER3);
    D(PFM_PMU_POWER4);
    D(PFM_PMU_POWER5);
    D(PFM_PMU_POWER5p);
    D(PFM_PMU_POWER6);
    D(PFM_PMU_POWER7);

    D(PFM_PMU_PERF_EVENT);
    D(PFM_PMU_INTEL_WSM);
    D(PFM_PMU_INTEL_WSM_DP);
    D(PFM_PMU_INTEL_WSM_UNC);

    D(PFM_PMU_AMD64_K7);
    D(PFM_PMU_AMD64_K8_REVB);
    D(PFM_PMU_AMD64_K8_REVC);
    D(PFM_PMU_AMD64_K8_REVD);
    D(PFM_PMU_AMD64_K8_REVE);
    D(PFM_PMU_AMD64_K8_REVF);
    D(PFM_PMU_AMD64_K8_REVG);
    D(PFM_PMU_AMD64_FAM10H_BARCELONA);
    D(PFM_PMU_AMD64_FAM10H_SHANGHAI);
    D(PFM_PMU_AMD64_FAM10H_ISTANBUL);

    D(PFM_PMU_ARM_CORTEX_A8);
    D(PFM_PMU_ARM_CORTEX_A9);

    D(PFM_PMU_TORRENT);

    D(PFM_PMU_INTEL_SNB);
    D(PFM_PMU_AMD64_FAM14H_BOBCAT);
    D(PFM_PMU_AMD64_FAM15H_INTERLAGOS);

    D(PFM_PMU_INTEL_SNB_EP);
    D(PFM_PMU_AMD64_FAM12H_LLANO);
    D(PFM_PMU_AMD64_FAM11H_TURION);
    D(PFM_PMU_INTEL_IVB);
    D(PFM_PMU_ARM_CORTEX_A15);

    D(PFM_PMU_INTEL_SNB_UNC_CB0);
    D(PFM_PMU_INTEL_SNB_UNC_CB1);
    D(PFM_PMU_INTEL_SNB_UNC_CB2);
    D(PFM_PMU_INTEL_SNB_UNC_CB3);

    D(PFM_PMU_INTEL_SNBEP_UNC_CB0);
    D(PFM_PMU_INTEL_SNBEP_UNC_CB1);
    D(PFM_PMU_INTEL_SNBEP_UNC_CB2);
    D(PFM_PMU_INTEL_SNBEP_UNC_CB3);
    D(PFM_PMU_INTEL_SNBEP_UNC_CB4);
    D(PFM_PMU_INTEL_SNBEP_UNC_CB5);
    D(PFM_PMU_INTEL_SNBEP_UNC_CB6);
    D(PFM_PMU_INTEL_SNBEP_UNC_CB7);
    D(PFM_PMU_INTEL_SNBEP_UNC_HA);
    D(PFM_PMU_INTEL_SNBEP_UNC_IMC0);
    D(PFM_PMU_INTEL_SNBEP_UNC_IMC1);
    D(PFM_PMU_INTEL_SNBEP_UNC_IMC2);
    D(PFM_PMU_INTEL_SNBEP_UNC_IMC3);
    D(PFM_PMU_INTEL_SNBEP_UNC_PCU);
    D(PFM_PMU_INTEL_SNBEP_UNC_QPI0);
    D(PFM_PMU_INTEL_SNBEP_UNC_QPI1);
    D(PFM_PMU_INTEL_SNBEP_UNC_UBOX);
    D(PFM_PMU_INTEL_SNBEP_UNC_R2PCIE);
    D(PFM_PMU_INTEL_SNBEP_UNC_R3QPI0);
    D(PFM_PMU_INTEL_SNBEP_UNC_R3QPI1);
    D(PFM_PMU_INTEL_KNC);

    D(PFM_PMU_S390X_CPUM_CF);

    D(PFM_PMU_ARM_1176);

    D(PFM_PMU_INTEL_IVB_EP);
    D(PFM_PMU_INTEL_HSW);

    D(PFM_PMU_INTEL_IVB_UNC_CB0);
    D(PFM_PMU_INTEL_IVB_UNC_CB1);
    D(PFM_PMU_INTEL_IVB_UNC_CB2);
    D(PFM_PMU_INTEL_IVB_UNC_CB3);

    D(PFM_PMU_POWER8);
    D(PFM_PMU_INTEL_RAPL);

    D(PFM_PMU_INTEL_SLM);
    D(PFM_PMU_AMD64_FAM15H_NB);

    D(PFM_PMU_ARM_QCOM_KRAIT);
    D(PFM_PMU_PERF_EVENT_RAW);

    D(PFM_PMU_INTEL_IVBEP_UNC_CB0);
    D(PFM_PMU_INTEL_IVBEP_UNC_CB1);
    D(PFM_PMU_INTEL_IVBEP_UNC_CB2);
    D(PFM_PMU_INTEL_IVBEP_UNC_CB3);
    D(PFM_PMU_INTEL_IVBEP_UNC_CB4);
    D(PFM_PMU_INTEL_IVBEP_UNC_CB5);
    D(PFM_PMU_INTEL_IVBEP_UNC_CB6);
    D(PFM_PMU_INTEL_IVBEP_UNC_CB7);
    D(PFM_PMU_INTEL_IVBEP_UNC_CB8);
    D(PFM_PMU_INTEL_IVBEP_UNC_CB9);
    D(PFM_PMU_INTEL_IVBEP_UNC_CB10);
    D(PFM_PMU_INTEL_IVBEP_UNC_CB11);
    D(PFM_PMU_INTEL_IVBEP_UNC_CB12);
    D(PFM_PMU_INTEL_IVBEP_UNC_CB13);
    D(PFM_PMU_INTEL_IVBEP_UNC_CB14);
    D(PFM_PMU_INTEL_IVBEP_UNC_HA0);
    D(PFM_PMU_INTEL_IVBEP_UNC_HA1);
    D(PFM_PMU_INTEL_IVBEP_UNC_IMC0);
    D(PFM_PMU_INTEL_IVBEP_UNC_IMC1);
    D(PFM_PMU_INTEL_IVBEP_UNC_IMC2);
    D(PFM_PMU_INTEL_IVBEP_UNC_IMC3);
    D(PFM_PMU_INTEL_IVBEP_UNC_IMC4);
    D(PFM_PMU_INTEL_IVBEP_UNC_IMC5);
    D(PFM_PMU_INTEL_IVBEP_UNC_IMC6);
    D(PFM_PMU_INTEL_IVBEP_UNC_IMC7);
    D(PFM_PMU_INTEL_IVBEP_UNC_PCU);
    D(PFM_PMU_INTEL_IVBEP_UNC_QPI0);
    D(PFM_PMU_INTEL_IVBEP_UNC_QPI1);
    D(PFM_PMU_INTEL_IVBEP_UNC_QPI2);
    D(PFM_PMU_INTEL_IVBEP_UNC_UBOX);
    D(PFM_PMU_INTEL_IVBEP_UNC_R2PCIE);
    D(PFM_PMU_INTEL_IVBEP_UNC_R3QPI0);
    D(PFM_PMU_INTEL_IVBEP_UNC_R3QPI1);
    D(PFM_PMU_INTEL_IVBEP_UNC_R3QPI2);
    D(PFM_PMU_INTEL_IVBEP_UNC_IRP);

    D(PFM_PMU_S390X_CPUM_SF);

    D(PFM_PMU_ARM_CORTEX_A57);
    D(PFM_PMU_ARM_CORTEX_A53);

    D(PFM_PMU_ARM_CORTEX_A7);

    D(PFM_PMU_INTEL_HSW_EP);
    D(PFM_PMU_INTEL_BDW);

    D(PFM_PMU_ARM_XGENE);

    D(PFM_PMU_INTEL_HSWEP_UNC_CB0);
    D(PFM_PMU_INTEL_HSWEP_UNC_CB1);
    D(PFM_PMU_INTEL_HSWEP_UNC_CB2);
    D(PFM_PMU_INTEL_HSWEP_UNC_CB3);
    D(PFM_PMU_INTEL_HSWEP_UNC_CB4);
    D(PFM_PMU_INTEL_HSWEP_UNC_CB5);
    D(PFM_PMU_INTEL_HSWEP_UNC_CB6);
    D(PFM_PMU_INTEL_HSWEP_UNC_CB7);
    D(PFM_PMU_INTEL_HSWEP_UNC_CB8);
    D(PFM_PMU_INTEL_HSWEP_UNC_CB9);
    D(PFM_PMU_INTEL_HSWEP_UNC_CB10);
    D(PFM_PMU_INTEL_HSWEP_UNC_CB11);
    D(PFM_PMU_INTEL_HSWEP_UNC_CB12);
    D(PFM_PMU_INTEL_HSWEP_UNC_CB13);
    D(PFM_PMU_INTEL_HSWEP_UNC_CB14);
    D(PFM_PMU_INTEL_HSWEP_UNC_CB15);
    D(PFM_PMU_INTEL_HSWEP_UNC_CB16);
    D(PFM_PMU_INTEL_HSWEP_UNC_CB17);
    D(PFM_PMU_INTEL_HSWEP_UNC_HA0);
    D(PFM_PMU_INTEL_HSWEP_UNC_HA1);
    D(PFM_PMU_INTEL_HSWEP_UNC_IMC0);
    D(PFM_PMU_INTEL_HSWEP_UNC_IMC1);
    D(PFM_PMU_INTEL_HSWEP_UNC_IMC2);
    D(PFM_PMU_INTEL_HSWEP_UNC_IMC3);
    D(PFM_PMU_INTEL_HSWEP_UNC_IMC4);
    D(PFM_PMU_INTEL_HSWEP_UNC_IMC5);
    D(PFM_PMU_INTEL_HSWEP_UNC_IMC6);
    D(PFM_PMU_INTEL_HSWEP_UNC_IMC7);
    D(PFM_PMU_INTEL_HSWEP_UNC_PCU);
    D(PFM_PMU_INTEL_HSWEP_UNC_QPI0);
    D(PFM_PMU_INTEL_HSWEP_UNC_QPI1);
    D(PFM_PMU_INTEL_HSWEP_UNC_UBOX);
    D(PFM_PMU_INTEL_HSWEP_UNC_R2PCIE);
    D(PFM_PMU_INTEL_HSWEP_UNC_R3QPI0);
    D(PFM_PMU_INTEL_HSWEP_UNC_R3QPI1);
    D(PFM_PMU_INTEL_HSWEP_UNC_R3QPI2);
    D(PFM_PMU_INTEL_HSWEP_UNC_IRP);
    D(PFM_PMU_INTEL_HSWEP_UNC_SB0);
    D(PFM_PMU_INTEL_HSWEP_UNC_SB1);
    D(PFM_PMU_INTEL_HSWEP_UNC_SB2);
    D(PFM_PMU_INTEL_HSWEP_UNC_SB3);

    D(PFM_PMU_POWERPC_NEST_MCS_READ_BW);
    D(PFM_PMU_POWERPC_NEST_MCS_WRITE_BW);

    D(PFM_PMU_INTEL_SKL);

    D(PFM_PMU_INTEL_BDW_EP);

    D(PFM_PMU_INTEL_GLM);

    D(PFM_PMU_INTEL_KNL);
    D(PFM_PMU_INTEL_KNL_UNC_IMC0);
    D(PFM_PMU_INTEL_KNL_UNC_IMC1);
    D(PFM_PMU_INTEL_KNL_UNC_IMC2);
    D(PFM_PMU_INTEL_KNL_UNC_IMC3);
    D(PFM_PMU_INTEL_KNL_UNC_IMC4);
    D(PFM_PMU_INTEL_KNL_UNC_IMC5);
    D(PFM_PMU_INTEL_KNL_UNC_IMC_UCLK0);
    D(PFM_PMU_INTEL_KNL_UNC_IMC_UCLK1);
    D(PFM_PMU_INTEL_KNL_UNC_EDC_ECLK0);
    D(PFM_PMU_INTEL_KNL_UNC_EDC_ECLK1);
    D(PFM_PMU_INTEL_KNL_UNC_EDC_ECLK2);
    D(PFM_PMU_INTEL_KNL_UNC_EDC_ECLK3);
    D(PFM_PMU_INTEL_KNL_UNC_EDC_ECLK4);
    D(PFM_PMU_INTEL_KNL_UNC_EDC_ECLK5);
    D(PFM_PMU_INTEL_KNL_UNC_EDC_ECLK6);
    D(PFM_PMU_INTEL_KNL_UNC_EDC_ECLK7);
    D(PFM_PMU_INTEL_KNL_UNC_EDC_UCLK0);
    D(PFM_PMU_INTEL_KNL_UNC_EDC_UCLK1);
    D(PFM_PMU_INTEL_KNL_UNC_EDC_UCLK2);
    D(PFM_PMU_INTEL_KNL_UNC_EDC_UCLK3);
    D(PFM_PMU_INTEL_KNL_UNC_EDC_UCLK4);
    D(PFM_PMU_INTEL_KNL_UNC_EDC_UCLK5);
    D(PFM_PMU_INTEL_KNL_UNC_EDC_UCLK6);
    D(PFM_PMU_INTEL_KNL_UNC_EDC_UCLK7);

    D(PFM_PMU_INTEL_KNL_UNC_CHA0);
    D(PFM_PMU_INTEL_KNL_UNC_CHA1);
    D(PFM_PMU_INTEL_KNL_UNC_CHA2);
    D(PFM_PMU_INTEL_KNL_UNC_CHA3);
    D(PFM_PMU_INTEL_KNL_UNC_CHA4);
    D(PFM_PMU_INTEL_KNL_UNC_CHA5);
    D(PFM_PMU_INTEL_KNL_UNC_CHA6);
    D(PFM_PMU_INTEL_KNL_UNC_CHA7);
    D(PFM_PMU_INTEL_KNL_UNC_CHA8);
    D(PFM_PMU_INTEL_KNL_UNC_CHA9);
    D(PFM_PMU_INTEL_KNL_UNC_CHA10);
    D(PFM_PMU_INTEL_KNL_UNC_CHA11);
    D(PFM_PMU_INTEL_KNL_UNC_CHA12);
    D(PFM_PMU_INTEL_KNL_UNC_CHA13);
    D(PFM_PMU_INTEL_KNL_UNC_CHA14);
    D(PFM_PMU_INTEL_KNL_UNC_CHA15);
    D(PFM_PMU_INTEL_KNL_UNC_CHA16);
    D(PFM_PMU_INTEL_KNL_UNC_CHA17);
    D(PFM_PMU_INTEL_KNL_UNC_CHA18);
    D(PFM_PMU_INTEL_KNL_UNC_CHA19);
    D(PFM_PMU_INTEL_KNL_UNC_CHA20);
    D(PFM_PMU_INTEL_KNL_UNC_CHA21);
    D(PFM_PMU_INTEL_KNL_UNC_CHA22);
    D(PFM_PMU_INTEL_KNL_UNC_CHA23);
    D(PFM_PMU_INTEL_KNL_UNC_CHA24);
    D(PFM_PMU_INTEL_KNL_UNC_CHA25);
    D(PFM_PMU_INTEL_KNL_UNC_CHA26);
    D(PFM_PMU_INTEL_KNL_UNC_CHA27);
    D(PFM_PMU_INTEL_KNL_UNC_CHA28);
    D(PFM_PMU_INTEL_KNL_UNC_CHA29);
    D(PFM_PMU_INTEL_KNL_UNC_CHA30);
    D(PFM_PMU_INTEL_KNL_UNC_CHA31);
    D(PFM_PMU_INTEL_KNL_UNC_CHA32);
    D(PFM_PMU_INTEL_KNL_UNC_CHA33);
    D(PFM_PMU_INTEL_KNL_UNC_CHA34);
    D(PFM_PMU_INTEL_KNL_UNC_CHA35);
    D(PFM_PMU_INTEL_KNL_UNC_CHA36);
    D(PFM_PMU_INTEL_KNL_UNC_CHA37);

    D(PFM_PMU_INTEL_KNL_UNC_UBOX);
    D(PFM_PMU_INTEL_KNL_UNC_M2PCIE);

    D(PFM_PMU_POWER9);

    D(PFM_PMU_INTEL_BDX_UNC_CB0);
    D(PFM_PMU_INTEL_BDX_UNC_CB1);
    D(PFM_PMU_INTEL_BDX_UNC_CB2);
    D(PFM_PMU_INTEL_BDX_UNC_CB3);
    D(PFM_PMU_INTEL_BDX_UNC_CB4);
    D(PFM_PMU_INTEL_BDX_UNC_CB5);
    D(PFM_PMU_INTEL_BDX_UNC_CB6);
    D(PFM_PMU_INTEL_BDX_UNC_CB7);
    D(PFM_PMU_INTEL_BDX_UNC_CB8);
    D(PFM_PMU_INTEL_BDX_UNC_CB9);
    D(PFM_PMU_INTEL_BDX_UNC_CB10);
    D(PFM_PMU_INTEL_BDX_UNC_CB11);
    D(PFM_PMU_INTEL_BDX_UNC_CB12);
    D(PFM_PMU_INTEL_BDX_UNC_CB13);
    D(PFM_PMU_INTEL_BDX_UNC_CB14);
    D(PFM_PMU_INTEL_BDX_UNC_CB15);
    D(PFM_PMU_INTEL_BDX_UNC_CB16);
    D(PFM_PMU_INTEL_BDX_UNC_CB17);
    D(PFM_PMU_INTEL_BDX_UNC_CB18);
    D(PFM_PMU_INTEL_BDX_UNC_CB19);
    D(PFM_PMU_INTEL_BDX_UNC_CB20);
    D(PFM_PMU_INTEL_BDX_UNC_CB21);
    D(PFM_PMU_INTEL_BDX_UNC_CB22);
    D(PFM_PMU_INTEL_BDX_UNC_CB23);
    D(PFM_PMU_INTEL_BDX_UNC_HA0);
    D(PFM_PMU_INTEL_BDX_UNC_HA1);
    D(PFM_PMU_INTEL_BDX_UNC_IMC0);
    D(PFM_PMU_INTEL_BDX_UNC_IMC1);
    D(PFM_PMU_INTEL_BDX_UNC_IMC2);
    D(PFM_PMU_INTEL_BDX_UNC_IMC3);
    D(PFM_PMU_INTEL_BDX_UNC_IMC4);
    D(PFM_PMU_INTEL_BDX_UNC_IMC5);
    D(PFM_PMU_INTEL_BDX_UNC_IMC6);
    D(PFM_PMU_INTEL_BDX_UNC_IMC7);
    D(PFM_PMU_INTEL_BDX_UNC_PCU);
    D(PFM_PMU_INTEL_BDX_UNC_QPI0);
    D(PFM_PMU_INTEL_BDX_UNC_QPI1);
    D(PFM_PMU_INTEL_BDX_UNC_QPI2);
    D(PFM_PMU_INTEL_BDX_UNC_UBOX);
    D(PFM_PMU_INTEL_BDX_UNC_R2PCIE);
    D(PFM_PMU_INTEL_BDX_UNC_R3QPI0);
    D(PFM_PMU_INTEL_BDX_UNC_R3QPI1);
    D(PFM_PMU_INTEL_BDX_UNC_R3QPI2);
    D(PFM_PMU_INTEL_BDX_UNC_IRP);
    D(PFM_PMU_INTEL_BDX_UNC_SB0);
    D(PFM_PMU_INTEL_BDX_UNC_SB1);
    D(PFM_PMU_INTEL_BDX_UNC_SB2);
    D(PFM_PMU_INTEL_BDX_UNC_SB3);

    D(PFM_PMU_AMD64_FAM17H);
    D(PFM_PMU_AMD64_FAM16H);

    D(PFM_PMU_INTEL_SKX);

    D(PFM_PMU_INTEL_SKX_UNC_CHA0);
    D(PFM_PMU_INTEL_SKX_UNC_CHA1);
    D(PFM_PMU_INTEL_SKX_UNC_CHA2);
    D(PFM_PMU_INTEL_SKX_UNC_CHA3);
    D(PFM_PMU_INTEL_SKX_UNC_CHA4);
    D(PFM_PMU_INTEL_SKX_UNC_CHA5);
    D(PFM_PMU_INTEL_SKX_UNC_CHA6);
    D(PFM_PMU_INTEL_SKX_UNC_CHA7);
    D(PFM_PMU_INTEL_SKX_UNC_CHA8);
    D(PFM_PMU_INTEL_SKX_UNC_CHA9);
    D(PFM_PMU_INTEL_SKX_UNC_CHA10);
    D(PFM_PMU_INTEL_SKX_UNC_CHA11);
    D(PFM_PMU_INTEL_SKX_UNC_CHA12);
    D(PFM_PMU_INTEL_SKX_UNC_CHA13);
    D(PFM_PMU_INTEL_SKX_UNC_CHA14);
    D(PFM_PMU_INTEL_SKX_UNC_CHA15);
    D(PFM_PMU_INTEL_SKX_UNC_CHA16);
    D(PFM_PMU_INTEL_SKX_UNC_CHA17);
    D(PFM_PMU_INTEL_SKX_UNC_CHA18);
    D(PFM_PMU_INTEL_SKX_UNC_CHA19);
    D(PFM_PMU_INTEL_SKX_UNC_CHA20);
    D(PFM_PMU_INTEL_SKX_UNC_CHA21);
    D(PFM_PMU_INTEL_SKX_UNC_CHA22);
    D(PFM_PMU_INTEL_SKX_UNC_CHA23);
    D(PFM_PMU_INTEL_SKX_UNC_CHA24);
    D(PFM_PMU_INTEL_SKX_UNC_CHA25);
    D(PFM_PMU_INTEL_SKX_UNC_CHA26);
    D(PFM_PMU_INTEL_SKX_UNC_CHA27);
    D(PFM_PMU_INTEL_SKX_UNC_IIO0);
    D(PFM_PMU_INTEL_SKX_UNC_IIO1);
    D(PFM_PMU_INTEL_SKX_UNC_IIO2);
    D(PFM_PMU_INTEL_SKX_UNC_IIO3);
    D(PFM_PMU_INTEL_SKX_UNC_IIO4);
    D(PFM_PMU_INTEL_SKX_UNC_IIO5);
    D(PFM_PMU_INTEL_SKX_UNC_IMC0);
    D(PFM_PMU_INTEL_SKX_UNC_IMC1);
    D(PFM_PMU_INTEL_SKX_UNC_IMC2);
    D(PFM_PMU_INTEL_SKX_UNC_IMC3);
    D(PFM_PMU_INTEL_SKX_UNC_IMC4);
    D(PFM_PMU_INTEL_SKX_UNC_IMC5);
    D(PFM_PMU_INTEL_SKX_UNC_IRP);
    D(PFM_PMU_INTEL_SKX_UNC_M2M0);
    D(PFM_PMU_INTEL_SKX_UNC_M2M1);
    D(PFM_PMU_INTEL_SKX_UNC_M3UPI0);
    D(PFM_PMU_INTEL_SKX_UNC_M3UPI1);
    D(PFM_PMU_INTEL_SKX_UNC_M3UPI2);
    D(PFM_PMU_INTEL_SKX_UNC_PCU);
    D(PFM_PMU_INTEL_SKX_UNC_UBOX);
    D(PFM_PMU_INTEL_SKX_UNC_UPI0);
    D(PFM_PMU_INTEL_SKX_UNC_UPI1);
    D(PFM_PMU_INTEL_SKX_UNC_UPI2);

    D(PFM_PMU_INTEL_KNM);
    D(PFM_PMU_INTEL_KNM_UNC_IMC0);
    D(PFM_PMU_INTEL_KNM_UNC_IMC1);
    D(PFM_PMU_INTEL_KNM_UNC_IMC2);
    D(PFM_PMU_INTEL_KNM_UNC_IMC3);
    D(PFM_PMU_INTEL_KNM_UNC_IMC4);
    D(PFM_PMU_INTEL_KNM_UNC_IMC5);
    D(PFM_PMU_INTEL_KNM_UNC_IMC_UCLK0);
    D(PFM_PMU_INTEL_KNM_UNC_IMC_UCLK1);
    D(PFM_PMU_INTEL_KNM_UNC_EDC_ECLK0);
    D(PFM_PMU_INTEL_KNM_UNC_EDC_ECLK1);
    D(PFM_PMU_INTEL_KNM_UNC_EDC_ECLK2);
    D(PFM_PMU_INTEL_KNM_UNC_EDC_ECLK3);
    D(PFM_PMU_INTEL_KNM_UNC_EDC_ECLK4);
    D(PFM_PMU_INTEL_KNM_UNC_EDC_ECLK5);
    D(PFM_PMU_INTEL_KNM_UNC_EDC_ECLK6);
    D(PFM_PMU_INTEL_KNM_UNC_EDC_ECLK7);
    D(PFM_PMU_INTEL_KNM_UNC_EDC_UCLK0);
    D(PFM_PMU_INTEL_KNM_UNC_EDC_UCLK1);
    D(PFM_PMU_INTEL_KNM_UNC_EDC_UCLK2);
    D(PFM_PMU_INTEL_KNM_UNC_EDC_UCLK3);
    D(PFM_PMU_INTEL_KNM_UNC_EDC_UCLK4);
    D(PFM_PMU_INTEL_KNM_UNC_EDC_UCLK5);
    D(PFM_PMU_INTEL_KNM_UNC_EDC_UCLK6);
    D(PFM_PMU_INTEL_KNM_UNC_EDC_UCLK7);

    D(PFM_PMU_INTEL_KNM_UNC_CHA0);
    D(PFM_PMU_INTEL_KNM_UNC_CHA1);
    D(PFM_PMU_INTEL_KNM_UNC_CHA2);
    D(PFM_PMU_INTEL_KNM_UNC_CHA3);
    D(PFM_PMU_INTEL_KNM_UNC_CHA4);
    D(PFM_PMU_INTEL_KNM_UNC_CHA5);
    D(PFM_PMU_INTEL_KNM_UNC_CHA6);
    D(PFM_PMU_INTEL_KNM_UNC_CHA7);
    D(PFM_PMU_INTEL_KNM_UNC_CHA8);
    D(PFM_PMU_INTEL_KNM_UNC_CHA9);
    D(PFM_PMU_INTEL_KNM_UNC_CHA10);
    D(PFM_PMU_INTEL_KNM_UNC_CHA11);
    D(PFM_PMU_INTEL_KNM_UNC_CHA12);
    D(PFM_PMU_INTEL_KNM_UNC_CHA13);
    D(PFM_PMU_INTEL_KNM_UNC_CHA14);
    D(PFM_PMU_INTEL_KNM_UNC_CHA15);
    D(PFM_PMU_INTEL_KNM_UNC_CHA16);
    D(PFM_PMU_INTEL_KNM_UNC_CHA17);
    D(PFM_PMU_INTEL_KNM_UNC_CHA18);
    D(PFM_PMU_INTEL_KNM_UNC_CHA19);
    D(PFM_PMU_INTEL_KNM_UNC_CHA20);
    D(PFM_PMU_INTEL_KNM_UNC_CHA21);
    D(PFM_PMU_INTEL_KNM_UNC_CHA22);
    D(PFM_PMU_INTEL_KNM_UNC_CHA23);
    D(PFM_PMU_INTEL_KNM_UNC_CHA24);
    D(PFM_PMU_INTEL_KNM_UNC_CHA25);
    D(PFM_PMU_INTEL_KNM_UNC_CHA26);
    D(PFM_PMU_INTEL_KNM_UNC_CHA27);
    D(PFM_PMU_INTEL_KNM_UNC_CHA28);
    D(PFM_PMU_INTEL_KNM_UNC_CHA29);
    D(PFM_PMU_INTEL_KNM_UNC_CHA30);
    D(PFM_PMU_INTEL_KNM_UNC_CHA31);
    D(PFM_PMU_INTEL_KNM_UNC_CHA32);
    D(PFM_PMU_INTEL_KNM_UNC_CHA33);
    D(PFM_PMU_INTEL_KNM_UNC_CHA34);
    D(PFM_PMU_INTEL_KNM_UNC_CHA35);
    D(PFM_PMU_INTEL_KNM_UNC_CHA36);
    D(PFM_PMU_INTEL_KNM_UNC_CHA37);

    D(PFM_PMU_INTEL_KNM_UNC_UBOX);
    D(PFM_PMU_INTEL_KNM_UNC_M2PCIE);
    D(PFM_PMU_ARM_THUNDERX2);

    D(PFM_PMU_INTEL_CLX);

    D(PFM_PMU_ARM_THUNDERX2_DMC0);
    D(PFM_PMU_ARM_THUNDERX2_DMC1);
    D(PFM_PMU_ARM_THUNDERX2_LLC0);
    D(PFM_PMU_ARM_THUNDERX2_LLC1);
    D(PFM_PMU_ARM_THUNDERX2_CCPI0);
    D(PFM_PMU_ARM_THUNDERX2_CCPI1);

    D(PFM_PMU_AMD64_FAM17H_ZEN1);
    D(PFM_PMU_AMD64_FAM17H_ZEN2);

    D(PFM_PMU_INTEL_TMT);
    D(PFM_PMU_INTEL_ICL);

    D(PFM_PMU_ARM_A64FX);
    D(PFM_PMU_ARM_N1);

    D(PFM_PMU_AMD64_FAM19H_ZEN3);
    D(PFM_PMU_AMD64_RAPL);
    D(PFM_PMU_AMD64_FAM19H_ZEN3_L3);

    D(PFM_PMU_INTEL_ICX);

    D(PFM_PMU_ARM_N2);

    D(PFM_PMU_ARM_KUNPENG);
    D(PFM_PMU_ARM_KUNPENG_UNC_SCCL1_DDRC0);
    D(PFM_PMU_ARM_KUNPENG_UNC_SCCL1_DDRC1);
    D(PFM_PMU_ARM_KUNPENG_UNC_SCCL1_DDRC2);
    D(PFM_PMU_ARM_KUNPENG_UNC_SCCL1_DDRC3);
    D(PFM_PMU_ARM_KUNPENG_UNC_SCCL3_DDRC0);
    D(PFM_PMU_ARM_KUNPENG_UNC_SCCL3_DDRC1);
    D(PFM_PMU_ARM_KUNPENG_UNC_SCCL3_DDRC2);
    D(PFM_PMU_ARM_KUNPENG_UNC_SCCL3_DDRC3);
    D(PFM_PMU_ARM_KUNPENG_UNC_SCCL5_DDRC0);
    D(PFM_PMU_ARM_KUNPENG_UNC_SCCL5_DDRC1);
    D(PFM_PMU_ARM_KUNPENG_UNC_SCCL5_DDRC2);
    D(PFM_PMU_ARM_KUNPENG_UNC_SCCL5_DDRC3);
    D(PFM_PMU_ARM_KUNPENG_UNC_SCCL7_DDRC0);
    D(PFM_PMU_ARM_KUNPENG_UNC_SCCL7_DDRC1);
    D(PFM_PMU_ARM_KUNPENG_UNC_SCCL7_DDRC2);
    D(PFM_PMU_ARM_KUNPENG_UNC_SCCL7_DDRC3);
    D(PFM_PMU_ARM_KUNPENG_UNC_SCCL1_HHA2);
    D(PFM_PMU_ARM_KUNPENG_UNC_SCCL1_HHA3);
    D(PFM_PMU_ARM_KUNPENG_UNC_SCCL3_HHA0);
    D(PFM_PMU_ARM_KUNPENG_UNC_SCCL3_HHA1);
    D(PFM_PMU_ARM_KUNPENG_UNC_SCCL5_HHA6);
    D(PFM_PMU_ARM_KUNPENG_UNC_SCCL5_HHA7);
    D(PFM_PMU_ARM_KUNPENG_UNC_SCCL7_HHA4);
    D(PFM_PMU_ARM_KUNPENG_UNC_SCCL7_HHA5);
    D(PFM_PMU_ARM_KUNPENG_UNC_SCCL1_L3C10);
    D(PFM_PMU_ARM_KUNPENG_UNC_SCCL1_L3C11);
    D(PFM_PMU_ARM_KUNPENG_UNC_SCCL1_L3C12);
    D(PFM_PMU_ARM_KUNPENG_UNC_SCCL1_L3C13);
    D(PFM_PMU_ARM_KUNPENG_UNC_SCCL1_L3C14);
    D(PFM_PMU_ARM_KUNPENG_UNC_SCCL1_L3C15);
    D(PFM_PMU_ARM_KUNPENG_UNC_SCCL1_L3C8);
    D(PFM_PMU_ARM_KUNPENG_UNC_SCCL1_L3C9);
    D(PFM_PMU_ARM_KUNPENG_UNC_SCCL3_L3C0);
    D(PFM_PMU_ARM_KUNPENG_UNC_SCCL3_L3C1);
    D(PFM_PMU_ARM_KUNPENG_UNC_SCCL3_L3C2);
    D(PFM_PMU_ARM_KUNPENG_UNC_SCCL3_L3C3);
    D(PFM_PMU_ARM_KUNPENG_UNC_SCCL3_L3C4);
    D(PFM_PMU_ARM_KUNPENG_UNC_SCCL3_L3C5);
    D(PFM_PMU_ARM_KUNPENG_UNC_SCCL3_L3C6);
    D(PFM_PMU_ARM_KUNPENG_UNC_SCCL3_L3C7);
    D(PFM_PMU_ARM_KUNPENG_UNC_SCCL5_L3C24);
    D(PFM_PMU_ARM_KUNPENG_UNC_SCCL5_L3C25);
    D(PFM_PMU_ARM_KUNPENG_UNC_SCCL5_L3C26);
    D(PFM_PMU_ARM_KUNPENG_UNC_SCCL5_L3C27);
    D(PFM_PMU_ARM_KUNPENG_UNC_SCCL5_L3C28);
    D(PFM_PMU_ARM_KUNPENG_UNC_SCCL5_L3C29);
    D(PFM_PMU_ARM_KUNPENG_UNC_SCCL5_L3C30);
    D(PFM_PMU_ARM_KUNPENG_UNC_SCCL5_L3C31);
    D(PFM_PMU_ARM_KUNPENG_UNC_SCCL7_L3C16);
    D(PFM_PMU_ARM_KUNPENG_UNC_SCCL7_L3C17);
    D(PFM_PMU_ARM_KUNPENG_UNC_SCCL7_L3C18);
    D(PFM_PMU_ARM_KUNPENG_UNC_SCCL7_L3C19);
    D(PFM_PMU_ARM_KUNPENG_UNC_SCCL7_L3C20);
    D(PFM_PMU_ARM_KUNPENG_UNC_SCCL7_L3C21);
    D(PFM_PMU_ARM_KUNPENG_UNC_SCCL7_L3C22);
    D(PFM_PMU_ARM_KUNPENG_UNC_SCCL7_L3C23);

    D(PFM_PMU_INTEL_SPR);

    D(PFM_PMU_POWER10);
    D(PFM_PMU_AMD64_FAM19H_ZEN4);
    D(PFM_PMU_ARM_V1);
    D(PFM_PMU_ARM_V2);

    return class_entry;
}

PERF_LOCAL PHP_MINIT_FUNCTION(perf_pmu)
{
    perf_pmu_enum_ce = register_class_PmuEnum();

    return SUCCESS;
}
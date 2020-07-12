// SPDX-License-Identifier: GPL-2.0-or-later
/*
 * Copyright 2013 Greg Ungerer <gerg@uclinux.org>
 * Copyright 2011 Freescale Semiconductor, Inc. All Rights Reserved.
 * Copyright 2011 Linaro Ltd.
 */

#include <linux/of_platform.h>
#include <asm/mach/arch.h>

#include "common.h"
#include "hardware.h"

static void __init imx50_init_early(void)
{
	mxc_set_cpu_type(MXC_CPU_MX50);
}

static void __init imx50_init_machine(void)
{
	struct device *parent = imx_soc_device_init();

	if (!parent)
		pr_warn("failed to initialize soc device\n");

	of_platform_default_populate(NULL, NULL, parent);

	imx_src_init();
}

static const char * const imx50_dt_board_compat[] __initconst = {
	"fsl,imx50",
	NULL
};

DT_MACHINE_START(IMX50_DT, "Freescale i.MX50 (Device Tree Support)")
	.init_early	= imx50_init_early,
	.init_machine	= imx50_init_machine,
	.dt_compat	= imx50_dt_board_compat,
MACHINE_END

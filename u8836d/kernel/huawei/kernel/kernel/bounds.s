	.arch armv7-a
	.fpu softvfp
	.eabi_attribute 20, 1	@ Tag_ABI_FP_denormal
	.eabi_attribute 21, 1	@ Tag_ABI_FP_exceptions
	.eabi_attribute 23, 3	@ Tag_ABI_FP_number_model
	.eabi_attribute 24, 1	@ Tag_ABI_align8_needed
	.eabi_attribute 25, 1	@ Tag_ABI_align8_preserved
	.eabi_attribute 26, 2	@ Tag_ABI_enum_size
	.eabi_attribute 30, 4	@ Tag_ABI_optimization_goals
	.eabi_attribute 34, 1	@ Tag_CPU_unaligned_access
	.eabi_attribute 18, 4	@ Tag_ABI_PCS_wchar_t
	.file	"bounds.c"
@ GNU C (GCC) version 4.7 (arm-linux-androideabi)
@	compiled by GNU C version 4.6.x-google 20120106 (prerelease), GMP version 5.0.5, MPFR version 3.1.1, MPC version 1.0.1
@ GGC heuristics: --param ggc-min-expand=97 --param ggc-min-heapsize=126819
@ options passed:  -nostdinc
@ -I /android/u8836d/kernel/huawei/kernel/arch/arm/include
@ -I arch/arm/include/generated -I include -I //common
@ -I ../mediatek/platform/mt6577/kernel/core/include/
@ -I ../mediatek/source/kernel/include/
@ -I ../mediatek/custom/out/huaqin77_cu_ics2/kernel/headset/
@ -I ../mediatek/custom/out/huaqin77_cu_ics2/kernel/lens/
@ -I ../mediatek/custom/out/huaqin77_cu_ics2/kernel/lens/inc/
@ -I ../mediatek/custom/out/huaqin77_cu_ics2/kernel/battery/
@ -I ../mediatek/custom/out/huaqin77_cu_ics2/kernel/flashlight/
@ -I ../mediatek/custom/out/huaqin77_cu_ics2/kernel/flashlight/inc/
@ -I ../mediatek/custom/out/huaqin77_cu_ics2/kernel/barometer/inc/
@ -I ../mediatek/custom/out/huaqin77_cu_ics2/kernel/accelerometer/
@ -I ../mediatek/custom/out/huaqin77_cu_ics2/kernel/accelerometer/inc/
@ -I ../mediatek/custom/out/huaqin77_cu_ics2/kernel/alsps/
@ -I ../mediatek/custom/out/huaqin77_cu_ics2/kernel/alsps/inc/
@ -I ../mediatek/custom/out/huaqin77_cu_ics2/kernel/rtc/inc/
@ -I ../mediatek/custom/out/huaqin77_cu_ics2/kernel/lcm/
@ -I ../mediatek/custom/out/huaqin77_cu_ics2/kernel/lcm/inc/
@ -I ../mediatek/custom/out/huaqin77_cu_ics2/kernel/magnetometer/
@ -I ../mediatek/custom/out/huaqin77_cu_ics2/kernel/magnetometer/inc/
@ -I ../mediatek/custom/out/huaqin77_cu_ics2/kernel/./
@ -I ../mediatek/custom/out/huaqin77_cu_ics2/kernel/kpd/
@ -I ../mediatek/custom/out/huaqin77_cu_ics2/kernel/camera/
@ -I ../mediatek/custom/out/huaqin77_cu_ics2/kernel/vibrator/
@ -I ../mediatek/custom/out/huaqin77_cu_ics2/kernel/sound/
@ -I ../mediatek/custom/out/huaqin77_cu_ics2/kernel/sound/inc/
@ -I ../mediatek/custom/out/huaqin77_cu_ics2/kernel/dct/
@ -I ../mediatek/custom/out/huaqin77_cu_ics2/kernel/hdmi/inc/
@ -I ../mediatek/custom/out/huaqin77_cu_ics2/kernel/touchpanel/
@ -I ../mediatek/custom/out/huaqin77_cu_ics2/kernel/imgsensor/
@ -I ../mediatek/custom/out/huaqin77_cu_ics2/kernel/imgsensor/inc/
@ -I ../mediatek/custom/out/huaqin77_cu_ics2/kernel/gyroscope/inc/
@ -I ../mediatek/custom/out/huaqin77_cu_ics2/kernel/eeprom/
@ -I ../mediatek/custom/out/huaqin77_cu_ics2/kernel/eeprom/inc/
@ -I ../mediatek/custom/out/huaqin77_cu_ics2/kernel/usb/
@ -I ../mediatek/custom/out/huaqin77_cu_ics2/kernel/leds/
@ -I ../mediatek/custom/out/huaqin77_cu_ics2/kernel/leds/inc/
@ -I ../mediatek/custom/out/huaqin77_cu_ics2/kernel/core/
@ -I ../mediatek/custom/out/huaqin77_cu_ics2/kernel/jogball/inc/
@ -I ../mediatek/custom/out/huaqin77_cu_ics2/kernel/ccci/
@ -I ../mediatek/custom/out/huaqin77_cu_ics2/kernel/fm/
@ -I ../mediatek/platform/mt6577/kernel/core/include -imultilib armv7-a
@ -iprefix /android/android-ndk-r8e/toolchains/arm-linux-androideabi-4.7/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7/
@ -D __KERNEL__ -D MODEM_3G -D __LINUX_ARM_ARCH__=7 -U arm
@ -D MTK_WAPI_SUPPORT -D MTK_SENSOR_SUPPORT -D CUSTOM_KERNEL_ALSPS
@ -D CUSTOM_KERNEL_MAGNETOMETER -D CUSTOM_KERNEL_ACCELEROMETER
@ -D MTK_BT_SUPPORT -D MTK_FM_SUPPORT -D MTK_M4U_SUPPORT
@ -D MTK_WLAN_SUPPORT -D MTK_WIFI_HOTSPOT_SUPPORT -D MTK_FM_SUPPORT
@ -D MTK_GPS_SUPPORT -D MTK_MULTI_STORAGE_SUPPORT -D MTK_EMMC_SUPPORT
@ -D MTK_FD_SUPPORT -D MTK_MASS_STORAGE -D MTK_2SDCARD_SWAP
@ -D MTK_SD_REINIT_SUPPORT -D HQ_PROJECT_A61P_HUAWEI
@ -D HQ_CHARGER_FOR_HUAWEI -D MTK_BICR_SUPPORT -D CONSTANT_FLASHLIGHT
@ -D MT9P017_MIPI_RAW -D S5K4E1FX_MIPI_RAW -D HI704_YUV -D GC0329_YUV
@ -D USER_BUILD_KERNEL -D MT6577 -D MT6620_FM -D MTK_MT6620 -D MT9P017_MIPI
@ -D GC0329_YUV -D FM50AF -D MT9P017AF -D MODEM_3G -D NT35516_DSI_3P2463
@ -D CONSTANT_FLASHLIGHT -D MT6620E3 -D LCM_WIDTH="540" -D LCM_HEIGHT="960"
@ -D MTK_LCM_PHYSICAL_ROTATION="0" -D MTK_SHARE_MODEM_SUPPORT="2"
@ -D MTK_SHARE_MODEM_CURRENT="2" -D EMMC_CHIP="4"
@ -D TARGET_BUILD_VARIANT="user" -D USER_BUILD_KERNEL -D CC_HAVE_ASM_GOTO
@ -D KBUILD_STR(s)=#s -D KBUILD_BASENAME=KBUILD_STR(bounds)
@ -D KBUILD_MODNAME=KBUILD_STR(bounds)
@ -isystem /android/android-ndk-r8e/toolchains/arm-linux-androideabi-4.7/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.7/include
@ -include include/generated/autoconf.h -MD kernel/.bounds.s.d
@ kernel/bounds.c -mbionic -fno-builtin-sincos -mlittle-endian -marm -mapcs
@ -mno-sched-prolog -mabi=aapcs-linux -mno-thumb-interwork -march=armv7-a
@ -mfloat-abi=soft -mfpu=vfp -mtls-dialect=gnu
@ -auxbase-strip kernel/bounds.s -Os -Wall -Wundef -Wstrict-prototypes
@ -Wno-trigraphs -Werror=implicit-function-declaration -Wno-format-security
@ -Wframe-larger-than=1024 -Wno-unused-but-set-variable
@ -Wdeclaration-after-statement -Wno-pointer-sign -fno-strict-aliasing
@ -fno-common -fno-delete-null-pointer-checks -fno-pic -fno-dwarf2-cfi-asm
@ -fno-stack-protector -fno-omit-frame-pointer -fno-optimize-sibling-calls
@ -fno-strict-overflow -fconserve-stack -fverbose-asm
@ options enabled:  -fauto-inc-dec -fbranch-count-reg -fcaller-saves
@ -fcombine-stack-adjustments -fcompare-elim -fcprop-registers
@ -fcrossjumping -fcse-follow-jumps -fdebug-types-section -fdefer-pop
@ -fdevirtualize -fearly-inlining -feliminate-unused-debug-types
@ -fexpensive-optimizations -fforward-propagate -ffunction-cse -fgcse
@ -fgcse-lm -fgnu-runtime -fguess-branch-probability -fident
@ -fif-conversion -fif-conversion2 -findirect-inlining -finline
@ -finline-atomics -finline-functions -finline-functions-called-once
@ -finline-small-functions -fipa-cp -fipa-profile -fipa-pure-const
@ -fipa-reference -fipa-sra -fira-share-save-slots -fira-share-spill-slots
@ -fivopts -fkeep-static-consts -fleading-underscore -fmath-errno
@ -fmerge-constants -fmerge-debug-strings -fmove-loop-invariants
@ -foptimize-register-move -fpartial-inlining -fpeephole -fpeephole2
@ -fprefetch-loop-arrays -freg-struct-return -fregmove -freorder-blocks
@ -freorder-functions -frerun-cse-after-loop
@ -fsched-critical-path-heuristic -fsched-dep-count-heuristic
@ -fsched-group-heuristic -fsched-interblock -fsched-last-insn-heuristic
@ -fsched-pressure -fsched-rank-heuristic -fsched-spec
@ -fsched-spec-insn-heuristic -fsched-stalled-insns-dep -fschedule-insns2
@ -fsection-anchors -fshow-column -fshrink-wrap -fsigned-zeros
@ -fsplit-ivs-in-unroller -fsplit-wide-types -fstrict-volatile-bitfields
@ -fthread-jumps -ftoplevel-reorder -ftrapping-math -ftree-bit-ccp
@ -ftree-builtin-call-dce -ftree-ccp -ftree-ch -ftree-copy-prop
@ -ftree-copyrename -ftree-cselim -ftree-dce -ftree-dominator-opts
@ -ftree-dse -ftree-forwprop -ftree-fre -ftree-loop-if-convert
@ -ftree-loop-im -ftree-loop-ivcanon -ftree-loop-optimize
@ -ftree-parallelize-loops= -ftree-phiprop -ftree-pre -ftree-pta
@ -ftree-reassoc -ftree-scev-cprop -ftree-sink -ftree-slp-vectorize
@ -ftree-sra -ftree-switch-conversion -ftree-tail-merge -ftree-ter
@ -ftree-vect-loop-version -ftree-vrp -funit-at-a-time -fverbose-asm
@ -fzero-initialized-in-bss -mandroid -mapcs-frame -marm -mbionic
@ -mlittle-endian -munaligned-access -mvectorize-with-neon-quad

	.text
	.align	2
	.global	foo
	.type	foo, %function
foo:
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 1, uses_anonymous_args = 0
	mov	ip, sp	@,
	stmfd	sp!, {fp, ip, lr, pc}	@,
	sub	fp, ip, #4	@,,
#APP
@ 17 "kernel/bounds.c" 1
	
->NR_PAGEFLAGS #22 __NR_PAGEFLAGS	@
@ 0 "" 2
@ 18 "kernel/bounds.c" 1
	
->MAX_NR_ZONES #3 __MAX_NR_ZONES	@
@ 0 "" 2
@ 19 "kernel/bounds.c" 1
	
->NR_PCG_FLAGS #7 __NR_PCG_FLAGS	@
@ 0 "" 2
	ldmfd	sp, {fp, sp, pc}	@
	.size	foo, .-foo
	.ident	"GCC: (GNU) 4.7"
	.section	.note.GNU-stack,"",%progbits

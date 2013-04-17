#Common headers
common_includes := hardware/qcom/display-caf/libgralloc
common_includes += hardware/qcom/display-caf/libgenlock
common_includes += hardware/qcom/display-caf/liboverlay
common_includes += hardware/qcom/display-caf/libcopybit
common_includes += hardware/qcom/display-caf/libqdutils
common_includes += hardware/qcom/display-caf/libhwcomposer
common_includes += hardware/qcom/display-caf/libexternal
common_includes += hardware/qcom/display-caf/libqservice

common_header_export_path := qcom/display

#Common libraries external to display-caf HAL
common_libs := liblog libutils libcutils libhardware

#Common C flags
common_flags := -DDEBUG_CALC_FPS -Wno-missing-field-initializers
#common_flags += -Werror

ifeq ($(ARCH_ARM_HAVE_NEON),true)
    common_flags += -D__ARM_HAVE_NEON
endif

ifeq ($(call is-board-platform-in-list, msm8974 msm8226 msm8610), true)
    common_flags += -DVENUS_COLOR_FORMAT
endif

common_deps  :=
kernel_includes :=

# Executed only on QCOM BSPs
ifeq ($(TARGET_USES_QCOM_BSP),true)
# This flag is used to compile out any features that depend on framework changes
    common_flags += -DQCOM_BSP
endif

ifeq ($(call is-vendor-board-platform,QCOM),true)
common_deps += $(TARGET_OUT_INTERMEDIATES)/KERNEL_OBJ/usr
kernel_includes += $(TARGET_OUT_INTERMEDIATES)/KERNEL_OBJ/usr/include
endif

ifneq ($(TARGET_DISPLAY_INSECURE_MM_HEAP),true)
    common_flags += -DSECURE_MM_HEAP
endif

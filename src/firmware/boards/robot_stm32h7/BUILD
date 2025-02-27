package(default_visibility = ["//visibility:public"])

load("//firmware:rules.bzl", "stm32h7_hal_library_files_genrule")

cc_binary(
    name = "robot_stm32h7_main",
    srcs = [
        "freertos.c",
        "main.c",
    ],
    defines = [
        "USE_HAL_DRIVER",
        "STM32H743xx",
    ],
    linkopts = [
        "-T$(location //firmware/boards/robot_stm32h7:STM32H743ZITx_FLASH.ld)",
        "-specs=nano.specs",
        "-lc",
        "-lm",
        "-lnosys",
    ],
    restricted_to = ["//cc_toolchain:stm32h7"],
    deps = [
        ":STM32H743ZITx_FLASH.ld",
        ":adc",
        ":dma",
        ":gpio",
        ":i2c",
        ":lwip",
        ":robot_stm32h7_main_lib",
        ":spi",
        "//firmware/app/logger",
        "//firmware/boards/robot_stm32h7/io:drivetrain",
        "//firmware/boards/robot_stm32h7/io:drivetrain_unit",
        "//firmware/boards/robot_stm32h7/io:gpio_pin",
        "//firmware/boards/robot_stm32h7/io:network_logger",
        "//firmware/boards/robot_stm32h7/io:power_monitor",
        "//firmware/boards/robot_stm32h7/io:pwm_pin",
        "//firmware/boards/robot_stm32h7/io:uart_logger",
        "//firmware/boards/robot_stm32h7/io:ublox_odinw262_communicator",
    ],
)

cc_library(
    name = "robot_stm32h7_main_lib",
    srcs = [
        "startup_stm32h743xx.s",
        "stm32h7xx_hal_msp.c",
        "stm32h7xx_it.c",
        "system_stm32h7xx.c",
    ],
    hdrs = [
        "FreeRTOSConfig.h",
        "stm32h7xx_hal_conf.h",
        "stm32h7xx_it.h",
    ],
    copts = [
        "-DSTM32H743xx",
        # We don't want to mark warnings as errors for 3rd party code
        "-Wno-error",
    ],
    restricted_to = ["//cc_toolchain:stm32h7"],
    deps = [
        ":crc",
        ":hal",
        ":lwip",
        ":tim",
        ":usart",
        "//firmware/boards/robot_stm32h7/io:proto_multicast_communication",
        "//firmware/boards/robot_stm32h7/io:ublox_odinw262_communicator",
        "//proto:tbots_nanopb_proto",
        "//shared:constants",
        "@nanopb",
    ],
    # This is _very_ important. If we don't do this, bazel will not link in the
    # interrupt handling code, which *will not* cause an error, and *will* cause
    # interrupts to stop working
    alwayslink = True,
)

cc_library(
    name = "crc",
    srcs = [
        "crc.c",
    ],
    hdrs = [
        "crc.h",
        "main.h",
    ],
    copts = [
        # We don't want to mark warnings as errors for 3rd party code
        "-Wno-error",
        "-DSTM32H743xx",
    ],
    restricted_to = ["//cc_toolchain:stm32h7"],
    deps = [
        ":hal",
    ],
    # This is _very_ important. If we don't do this, bazel will not link in the
    # interrupt handling code, which *will not* cause an error, and *will* cause
    # interrupts to stop working
    alwayslink = True,
)

cc_library(
    name = "tim",
    srcs = [
        "tim.c",
    ],
    hdrs = [
        "main.h",
        "tim.h",
    ],
    copts = [
        # We don't want to mark warnings as errors for 3rd party code
        "-Wno-error",
        "-DSTM32H743xx",
    ],
    restricted_to = ["//cc_toolchain:stm32h7"],
    deps = [
        ":hal",
    ],
    # This is _very_ important. If we don't do this, bazel will not link in the
    # interrupt handling code, which *will not* cause an error, and *will* cause
    # interrupts to stop working
    alwayslink = True,
)

cc_library(
    name = "gpio",
    srcs = [
        "gpio.c",
    ],
    hdrs = [
        "gpio.h",
        "main.h",
    ],
    copts = [
        # We don't want to mark warnings as errors for 3rd party code
        "-Wno-error",
        "-DSTM32H743xx",
    ],
    restricted_to = ["//cc_toolchain:stm32h7"],
    deps = [
        ":hal",
    ],
    # This is _very_ important. If we don't do this, bazel will not link in the
    # interrupt handling code, which *will not* cause an error, and *will* cause
    # interrupts to stop working
    alwayslink = True,
)

cc_library(
    name = "adc",
    srcs = [
        "adc.c",
    ],
    hdrs = [
        "adc.h",
        "main.h",
    ],
    copts = [
        # We don't want to mark warnings as errors for 3rd party code
        "-Wno-error",
        "-DSTM32H743xx",
    ],
    restricted_to = ["//cc_toolchain:stm32h7"],
    deps = [
        ":hal",
    ],
    # This is _very_ important. If we don't do this, bazel will not link in the
    # interrupt handling code, which *will not* cause an error, and *will* cause
    # interrupts to stop working
    alwayslink = True,
)

cc_library(
    name = "spi",
    srcs = [
        "spi.c",
    ],
    hdrs = [
        "main.h",
        "spi.h",
    ],
    copts = [
        # We don't want to mark warnings as errors for 3rd party code
        "-Wno-error",
        "-DSTM32H743xx",
    ],
    restricted_to = ["//cc_toolchain:stm32h7"],
    deps = [
        ":hal",
    ],
    # This is _very_ important. If we don't do this, bazel will not link in the
    # interrupt handling code, which *will not* cause an error, and *will* cause
    # interrupts to stop working
    alwayslink = True,
)

cc_library(
    name = "fatfs",
    srcs = [
        "Middlewares/Third_Party/FatFs/src/diskio.c",
        "Middlewares/Third_Party/FatFs/src/ff.c",
        "Middlewares/Third_Party/FatFs/src/ff_gen_drv.c",
        "Middlewares/Third_Party/FatFs/src/option/syscall.c",
        "bsp_driver_sd.c",
        "fatfs.c",
        "sd_diskio.c",
        "sdmmc.c",
    ],
    hdrs = [
        "Middlewares/Third_Party/FatFs/src/diskio.h",
        "Middlewares/Third_Party/FatFs/src/ff.h",
        "Middlewares/Third_Party/FatFs/src/ff_gen_drv.h",
        "Middlewares/Third_Party/FatFs/src/ffconf_template.h",
        "Middlewares/Third_Party/FatFs/src/integer.h",
        "bsp_driver_sd.h",
        "fatfs.h",
        "ffconf.h",
        "main.h",
        "sd_diskio.h",
        "sdmmc.h",
    ],
    copts = [
        # We don't want to mark warnings as errors for 3rd party code
        "-Wno-error",
        "-DSTM32H743xx",
    ],
    includes = [
        "./",
        "Drivers/CMSIS/DSP/Include/",
        "Drivers/CMSIS/Device/ST/STM32H7xx/Include/",
        "Drivers/CMSIS/Include/",
        "Drivers/CMSIS/RTOS2/Include/",
        "Drivers/CMSIS/RTOS2/Template/",
        "Middlewares/Third_Party/FatFs/src/",
        "Middlewares/Third_Party/FatFs/src/drivers/",
    ],
    restricted_to = ["//cc_toolchain:stm32h7"],
    deps = [
        ":hal",
    ],
    # This is _very_ important. If we don't do this, bazel will not link in the
    # interrupt handling code, which *will not* cause an error, and *will* cause
    # interrupts to stop working
    alwayslink = True,
)

cc_library(
    name = "dma",
    srcs = [
        "dma.c",
    ],
    hdrs = [
        "dma.h",
        "main.h",
    ],
    copts = [
        # We don't want to mark warnings as errors for 3rd party code
        "-Wno-error",
        "-DSTM32H743xx",
    ],
    restricted_to = ["//cc_toolchain:stm32h7"],
    deps = [
        ":hal",
    ],
    # This is _very_ important. If we don't do this, bazel will not link in the
    # interrupt handling code, which *will not* cause an error, and *will* cause
    # interrupts to stop working
    alwayslink = True,
)

cc_library(
    name = "i2c",
    srcs = [
        "i2c.c",
    ],
    hdrs = [
        "i2c.h",
        "main.h",
    ],
    copts = [
        # We don't want to mark warnings as errors for 3rd party code
        "-Wno-error",
        "-DSTM32H743xx",
    ],
    restricted_to = ["//cc_toolchain:stm32h7"],
    deps = [
        ":hal",
    ],
    # This is _very_ important. If we don't do this, bazel will not link in the
    # interrupt handling code, which *will not* cause an error, and *will* cause
    # interrupts to stop working
    alwayslink = True,
)

cc_library(
    name = "usart",
    srcs = [
        "usart.c",
    ],
    hdrs = [
        "main.h",
        "usart.h",
    ],
    copts = [
        # We don't want to mark warnings as errors for 3rd party code
        "-Wno-error",
        "-DSTM32H743xx",
    ],
    restricted_to = ["//cc_toolchain:stm32h7"],
    deps = [
        ":hal",
    ],
    # This is _very_ important. If we don't do this, bazel will not link in the
    # interrupt handling code, which *will not* cause an error, and *will* cause
    # interrupts to stop working
    alwayslink = True,
)

stm32h7_hal_library_files_genrule("hal_library_files")

# We got some of this list of hdrs/srcs by looking at the Makefile STM32CubeMX generates,
# (if the project type is set to `MakeFile`) and others by simply attempting compilation,
# seeing where stuff failed, and finding the correct header in the downloaded files
cc_library(
    name = "hal",
    srcs = [
        "Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal.c",
        "Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_adc.c",
        "Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_adc_ex.c",
        "Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_cortex.c",
        "Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_crc.c",
        "Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_crc_ex.c",
        "Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_dma.c",
        "Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_dma_ex.c",
        "Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_eth.c",
        "Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_eth_ex.c",
        "Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_exti.c",
        "Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_flash.c",
        "Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_flash_ex.c",
        "Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_gpio.c",
        "Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_hsem.c",
        "Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_i2c.c",
        "Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_i2c_ex.c",
        "Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_mdma.c",
        "Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_pcd.c",
        "Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_pcd_ex.c",
        "Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_pwr.c",
        "Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_pwr_ex.c",
        "Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_rcc.c",
        "Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_rcc_ex.c",
        "Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_sd.c",
        "Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_sd_ex.c",
        "Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_smbus.c",
        "Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_spi.c",
        "Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_spi_ex.c",
        "Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_tim.c",
        "Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_tim_ex.c",
        "Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_uart.c",
        "Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_uart_ex.c",
        "Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_ll_adc.c",
        "Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_ll_delayblock.c",
        "Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_ll_sdmmc.c",
        "Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_ll_usb.c",
    ],
    hdrs = [
        "Drivers/CMSIS/Device/ST/STM32H7xx/Include/stm32h743xx.h",
        "Drivers/CMSIS/Device/ST/STM32H7xx/Include/system_stm32h7xx.h",
        "Drivers/CMSIS/Include/cmsis_compiler.h",
        "Drivers/CMSIS/Include/cmsis_gcc.h",
        "Drivers/CMSIS/Include/cmsis_version.h",
        "Drivers/CMSIS/Include/core_cm7.h",
        "Drivers/CMSIS/Include/mpu_armv7.h",
        "Drivers/STM32H7xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h",
        "Drivers/STM32H7xx_HAL_Driver/Inc/stm32h7xx_hal.h",
        "Drivers/STM32H7xx_HAL_Driver/Inc/stm32h7xx_hal_adc.h",
        "Drivers/STM32H7xx_HAL_Driver/Inc/stm32h7xx_hal_adc_ex.h",
        "Drivers/STM32H7xx_HAL_Driver/Inc/stm32h7xx_hal_cortex.h",
        "Drivers/STM32H7xx_HAL_Driver/Inc/stm32h7xx_hal_crc.h",
        "Drivers/STM32H7xx_HAL_Driver/Inc/stm32h7xx_hal_crc_ex.h",
        "Drivers/STM32H7xx_HAL_Driver/Inc/stm32h7xx_hal_def.h",
        "Drivers/STM32H7xx_HAL_Driver/Inc/stm32h7xx_hal_dma.h",
        "Drivers/STM32H7xx_HAL_Driver/Inc/stm32h7xx_hal_dma_ex.h",
        "Drivers/STM32H7xx_HAL_Driver/Inc/stm32h7xx_hal_eth.h",
        "Drivers/STM32H7xx_HAL_Driver/Inc/stm32h7xx_hal_eth_ex.h",
        "Drivers/STM32H7xx_HAL_Driver/Inc/stm32h7xx_hal_exti.h",
        "Drivers/STM32H7xx_HAL_Driver/Inc/stm32h7xx_hal_flash.h",
        "Drivers/STM32H7xx_HAL_Driver/Inc/stm32h7xx_hal_flash_ex.h",
        "Drivers/STM32H7xx_HAL_Driver/Inc/stm32h7xx_hal_gpio.h",
        "Drivers/STM32H7xx_HAL_Driver/Inc/stm32h7xx_hal_gpio_ex.h",
        "Drivers/STM32H7xx_HAL_Driver/Inc/stm32h7xx_hal_hsem.h",
        "Drivers/STM32H7xx_HAL_Driver/Inc/stm32h7xx_hal_i2c.h",
        "Drivers/STM32H7xx_HAL_Driver/Inc/stm32h7xx_hal_i2c_ex.h",
        "Drivers/STM32H7xx_HAL_Driver/Inc/stm32h7xx_hal_mdma.h",
        "Drivers/STM32H7xx_HAL_Driver/Inc/stm32h7xx_hal_pcd.h",
        "Drivers/STM32H7xx_HAL_Driver/Inc/stm32h7xx_hal_pcd_ex.h",
        "Drivers/STM32H7xx_HAL_Driver/Inc/stm32h7xx_hal_pwr.h",
        "Drivers/STM32H7xx_HAL_Driver/Inc/stm32h7xx_hal_pwr_ex.h",
        "Drivers/STM32H7xx_HAL_Driver/Inc/stm32h7xx_hal_rcc.h",
        "Drivers/STM32H7xx_HAL_Driver/Inc/stm32h7xx_hal_rcc_ex.h",
        "Drivers/STM32H7xx_HAL_Driver/Inc/stm32h7xx_hal_sd.h",
        "Drivers/STM32H7xx_HAL_Driver/Inc/stm32h7xx_hal_sd_ex.h",
        "Drivers/STM32H7xx_HAL_Driver/Inc/stm32h7xx_hal_smbus.h",
        "Drivers/STM32H7xx_HAL_Driver/Inc/stm32h7xx_hal_spi.h",
        "Drivers/STM32H7xx_HAL_Driver/Inc/stm32h7xx_hal_spi_ex.h",
        "Drivers/STM32H7xx_HAL_Driver/Inc/stm32h7xx_hal_tim.h",
        "Drivers/STM32H7xx_HAL_Driver/Inc/stm32h7xx_hal_tim_ex.h",
        "Drivers/STM32H7xx_HAL_Driver/Inc/stm32h7xx_hal_uart.h",
        "Drivers/STM32H7xx_HAL_Driver/Inc/stm32h7xx_hal_uart_ex.h",
        "Drivers/STM32H7xx_HAL_Driver/Inc/stm32h7xx_ll_adc.h",
        "Drivers/STM32H7xx_HAL_Driver/Inc/stm32h7xx_ll_delayblock.h",
        "Drivers/STM32H7xx_HAL_Driver/Inc/stm32h7xx_ll_sdmmc.h",
        "Drivers/STM32H7xx_HAL_Driver/Inc/stm32h7xx_ll_usb.h",
        "stm32h7xx_hal_conf.h",
    ],
    copts = [
        # We don't want to mark warnings as errors for 3rd party code
        "-Wno-error",
    ],
    defines = [
        "STM32H743xx",
    ],
    includes = [
        "./",
        "Drivers/CMSIS/Device/ST/STM32H7xx/Include",
        "Drivers/STM32H7xx_HAL_Driver/Inc",
    ],
    restricted_to = ["//cc_toolchain:stm32h7"],
    deps = [
        ":rtos",
    ],
)

cc_library(
    name = "cmsis",
    srcs = [
    ],
    hdrs = [
        "Drivers/CMSIS/DSP/Include/arm_common_tables.h",
        "Drivers/CMSIS/DSP/Include/arm_const_structs.h",
        "Drivers/CMSIS/DSP/Include/arm_math.h",
        "Drivers/CMSIS/Include/cmsis_compiler.h",
        "Drivers/CMSIS/Include/cmsis_gcc.h",
        "Drivers/CMSIS/Include/cmsis_version.h",
        "Drivers/CMSIS/Include/core_cm7.h",
        "Drivers/CMSIS/Include/mpu_armv7.h",
    ],
    copts = [
        # We don't want to mark warnings as errors for 3rd party code
        "-Wno-error",
    ],
    defines = [
        "STM32H743xx",
        "ARM_MATH_CM7",
    ],
    includes = [
        "./",
        "Drivers/CMSIS/DSP/Include/",
        "Drivers/CMSIS/Device/ST/STM32H7xx/Include/",
        "Drivers/CMSIS/Include/",
        "Drivers/CMSIS/RTOS2/Include/",
        "Drivers/CMSIS/RTOS2/Template/",
    ],
    restricted_to = ["//cc_toolchain:stm32h7"],
)

cc_library(
    name = "rtos",
    srcs = [
        "Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2/cmsis_os2.c",
        "Middlewares/Third_Party/FreeRTOS/Source/event_groups.c",
        "Middlewares/Third_Party/FreeRTOS/Source/list.c",
        "Middlewares/Third_Party/FreeRTOS/Source/portable/Common/mpu_wrappers.c",
        "Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1/port.c",
        "Middlewares/Third_Party/FreeRTOS/Source/portable/MemMang/heap_4.c",
        "Middlewares/Third_Party/FreeRTOS/Source/queue.c",
        "Middlewares/Third_Party/FreeRTOS/Source/stream_buffer.c",
        "Middlewares/Third_Party/FreeRTOS/Source/tasks.c",
        "Middlewares/Third_Party/FreeRTOS/Source/timers.c",
    ],
    hdrs = [
        "Drivers/CMSIS/Device/ST/STM32H7xx/Include/stm32h743xx.h",
        "Drivers/CMSIS/Device/ST/STM32H7xx/Include/stm32h7xx.h",
        "Drivers/CMSIS/Device/ST/STM32H7xx/Include/system_stm32h7xx.h",
        "Drivers/STM32H7xx_HAL_Driver/Inc/stm32h7xx_hal.h",
        "FreeRTOSConfig.h",
        "Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2/cmsis_os.h",
        "Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2/cmsis_os2.h",
        "Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2/freertos_mpool.h",
        "Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2/freertos_os2.h",
        "Middlewares/Third_Party/FreeRTOS/Source/include/FreeRTOS.h",
        "Middlewares/Third_Party/FreeRTOS/Source/include/deprecated_definitions.h",
        "Middlewares/Third_Party/FreeRTOS/Source/include/event_groups.h",
        "Middlewares/Third_Party/FreeRTOS/Source/include/list.h",
        "Middlewares/Third_Party/FreeRTOS/Source/include/mpu_prototypes.h",
        "Middlewares/Third_Party/FreeRTOS/Source/include/mpu_wrappers.h",
        "Middlewares/Third_Party/FreeRTOS/Source/include/portable.h",
        "Middlewares/Third_Party/FreeRTOS/Source/include/projdefs.h",
        "Middlewares/Third_Party/FreeRTOS/Source/include/queue.h",
        "Middlewares/Third_Party/FreeRTOS/Source/include/semphr.h",
        "Middlewares/Third_Party/FreeRTOS/Source/include/stack_macros.h",
        "Middlewares/Third_Party/FreeRTOS/Source/include/stream_buffer.h",
        "Middlewares/Third_Party/FreeRTOS/Source/include/task.h",
        "Middlewares/Third_Party/FreeRTOS/Source/include/timers.h",
        "Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1/portmacro.h",
        "stm32h7xx_hal_conf.h",
    ],
    copts = [
        # We don't want to mark warnings as errors for 3rd party code
        "-Wno-error",
    ],
    defines = [
        "STM32H743xx",
    ],
    includes = [
        "./",
        "Drivers/CMSIS/Device/ST/STM32H7xx/Include/",
        "Drivers/STM32H7xx_HAL_Driver/Inc/",
        "Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2/",
        "Middlewares/Third_Party/FreeRTOS/Source/include",
        "Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1",
    ],
    restricted_to = ["//cc_toolchain:stm32h7"],
    deps = [":cmsis"],
)

cc_library(
    name = "lwip",
    srcs = [
        "Drivers/BSP/Components/lan8742/lan8742.c",
        "Middlewares/Third_Party/LwIP/src/api/api_lib.c",
        "Middlewares/Third_Party/LwIP/src/api/api_msg.c",
        "Middlewares/Third_Party/LwIP/src/api/err.c",
        "Middlewares/Third_Party/LwIP/src/api/netbuf.c",
        "Middlewares/Third_Party/LwIP/src/api/netdb.c",
        "Middlewares/Third_Party/LwIP/src/api/netifapi.c",
        "Middlewares/Third_Party/LwIP/src/api/sockets.c",
        "Middlewares/Third_Party/LwIP/src/api/tcpip.c",
        "Middlewares/Third_Party/LwIP/src/apps/snmp/snmp_netconn.c",
        "Middlewares/Third_Party/LwIP/src/core/def.c",
        "Middlewares/Third_Party/LwIP/src/core/dns.c",
        "Middlewares/Third_Party/LwIP/src/core/inet_chksum.c",
        "Middlewares/Third_Party/LwIP/src/core/init.c",
        "Middlewares/Third_Party/LwIP/src/core/ip.c",
        "Middlewares/Third_Party/LwIP/src/core/ipv4/autoip.c",
        "Middlewares/Third_Party/LwIP/src/core/ipv4/dhcp.c",
        "Middlewares/Third_Party/LwIP/src/core/ipv4/etharp.c",
        "Middlewares/Third_Party/LwIP/src/core/ipv4/icmp.c",
        "Middlewares/Third_Party/LwIP/src/core/ipv4/igmp.c",
        "Middlewares/Third_Party/LwIP/src/core/ipv4/ip4.c",
        "Middlewares/Third_Party/LwIP/src/core/ipv4/ip4_addr.c",
        "Middlewares/Third_Party/LwIP/src/core/ipv4/ip4_frag.c",
        "Middlewares/Third_Party/LwIP/src/core/ipv6/dhcp6.c",
        "Middlewares/Third_Party/LwIP/src/core/ipv6/ethip6.c",
        "Middlewares/Third_Party/LwIP/src/core/ipv6/icmp6.c",
        "Middlewares/Third_Party/LwIP/src/core/ipv6/inet6.c",
        "Middlewares/Third_Party/LwIP/src/core/ipv6/ip6.c",
        "Middlewares/Third_Party/LwIP/src/core/ipv6/ip6_addr.c",
        "Middlewares/Third_Party/LwIP/src/core/ipv6/ip6_frag.c",
        "Middlewares/Third_Party/LwIP/src/core/ipv6/mld6.c",
        "Middlewares/Third_Party/LwIP/src/core/ipv6/nd6.c",
        "Middlewares/Third_Party/LwIP/src/core/mem.c",
        "Middlewares/Third_Party/LwIP/src/core/memp.c",
        "Middlewares/Third_Party/LwIP/src/core/netif.c",
        "Middlewares/Third_Party/LwIP/src/core/pbuf.c",
        "Middlewares/Third_Party/LwIP/src/core/raw.c",
        "Middlewares/Third_Party/LwIP/src/core/stats.c",
        "Middlewares/Third_Party/LwIP/src/core/sys.c",
        "Middlewares/Third_Party/LwIP/src/core/tcp.c",
        "Middlewares/Third_Party/LwIP/src/core/tcp_in.c",
        "Middlewares/Third_Party/LwIP/src/core/tcp_out.c",
        "Middlewares/Third_Party/LwIP/src/core/timeouts.c",
        "Middlewares/Third_Party/LwIP/src/core/udp.c",
        "Middlewares/Third_Party/LwIP/src/netif/ethernet.c",
        "Middlewares/Third_Party/LwIP/src/netif/ppp/auth.c",
        "Middlewares/Third_Party/LwIP/src/netif/ppp/ccp.c",
        "Middlewares/Third_Party/LwIP/src/netif/ppp/chap-md5.c",
        "Middlewares/Third_Party/LwIP/src/netif/ppp/chap-new.c",
        "Middlewares/Third_Party/LwIP/src/netif/ppp/chap_ms.c",
        "Middlewares/Third_Party/LwIP/src/netif/ppp/demand.c",
        "Middlewares/Third_Party/LwIP/src/netif/ppp/eap.c",
        "Middlewares/Third_Party/LwIP/src/netif/ppp/ecp.c",
        "Middlewares/Third_Party/LwIP/src/netif/ppp/eui64.c",
        "Middlewares/Third_Party/LwIP/src/netif/ppp/fsm.c",
        "Middlewares/Third_Party/LwIP/src/netif/ppp/ipcp.c",
        "Middlewares/Third_Party/LwIP/src/netif/ppp/ipv6cp.c",
        "Middlewares/Third_Party/LwIP/src/netif/ppp/lcp.c",
        "Middlewares/Third_Party/LwIP/src/netif/ppp/magic.c",
        "Middlewares/Third_Party/LwIP/src/netif/ppp/mppe.c",
        "Middlewares/Third_Party/LwIP/src/netif/ppp/multilink.c",
        "Middlewares/Third_Party/LwIP/src/netif/ppp/polarssl/arc4.c",
        "Middlewares/Third_Party/LwIP/src/netif/ppp/polarssl/des.c",
        "Middlewares/Third_Party/LwIP/src/netif/ppp/polarssl/md4.c",
        "Middlewares/Third_Party/LwIP/src/netif/ppp/polarssl/md5.c",
        "Middlewares/Third_Party/LwIP/src/netif/ppp/polarssl/sha1.c",
        "Middlewares/Third_Party/LwIP/src/netif/ppp/ppp.c",
        "Middlewares/Third_Party/LwIP/src/netif/ppp/pppapi.c",
        "Middlewares/Third_Party/LwIP/src/netif/ppp/pppcrypt.c",
        "Middlewares/Third_Party/LwIP/src/netif/ppp/pppoe.c",
        "Middlewares/Third_Party/LwIP/src/netif/ppp/pppol2tp.c",
        "Middlewares/Third_Party/LwIP/src/netif/ppp/pppos.c",
        "Middlewares/Third_Party/LwIP/src/netif/ppp/upap.c",
        "Middlewares/Third_Party/LwIP/src/netif/ppp/utils.c",
        "Middlewares/Third_Party/LwIP/src/netif/ppp/vj.c",
        "Middlewares/Third_Party/LwIP/system/OS/sys_arch.c",
        "ethernetif.c",
        "lwip.c",
    ],
    hdrs = [
        "Drivers/BSP/Components/lan8742/lan8742.h",
        "FreeRTOSConfig.h",
        "Middlewares/Third_Party/LwIP/src/include/lwip/altcp.h",
        "Middlewares/Third_Party/LwIP/src/include/lwip/api.h",
        "Middlewares/Third_Party/LwIP/src/include/lwip/apps/snmp_opts.h",
        "Middlewares/Third_Party/LwIP/src/include/lwip/arch.h",
        "Middlewares/Third_Party/LwIP/src/include/lwip/autoip.h",
        "Middlewares/Third_Party/LwIP/src/include/lwip/debug.h",
        "Middlewares/Third_Party/LwIP/src/include/lwip/def.h",
        "Middlewares/Third_Party/LwIP/src/include/lwip/dhcp.h",
        "Middlewares/Third_Party/LwIP/src/include/lwip/dhcp6.h",
        "Middlewares/Third_Party/LwIP/src/include/lwip/dns.h",
        "Middlewares/Third_Party/LwIP/src/include/lwip/err.h",
        "Middlewares/Third_Party/LwIP/src/include/lwip/errno.h",
        "Middlewares/Third_Party/LwIP/src/include/lwip/etharp.h",
        "Middlewares/Third_Party/LwIP/src/include/lwip/ethip6.h",
        "Middlewares/Third_Party/LwIP/src/include/lwip/icmp.h",
        "Middlewares/Third_Party/LwIP/src/include/lwip/icmp6.h",
        "Middlewares/Third_Party/LwIP/src/include/lwip/igmp.h",
        "Middlewares/Third_Party/LwIP/src/include/lwip/inet.h",
        "Middlewares/Third_Party/LwIP/src/include/lwip/inet_chksum.h",
        "Middlewares/Third_Party/LwIP/src/include/lwip/init.h",
        "Middlewares/Third_Party/LwIP/src/include/lwip/ip.h",
        "Middlewares/Third_Party/LwIP/src/include/lwip/ip4.h",
        "Middlewares/Third_Party/LwIP/src/include/lwip/ip4_addr.h",
        "Middlewares/Third_Party/LwIP/src/include/lwip/ip4_frag.h",
        "Middlewares/Third_Party/LwIP/src/include/lwip/ip6.h",
        "Middlewares/Third_Party/LwIP/src/include/lwip/ip6_addr.h",
        "Middlewares/Third_Party/LwIP/src/include/lwip/ip6_frag.h",
        "Middlewares/Third_Party/LwIP/src/include/lwip/ip6_zone.h",
        "Middlewares/Third_Party/LwIP/src/include/lwip/ip_addr.h",
        "Middlewares/Third_Party/LwIP/src/include/lwip/mem.h",
        "Middlewares/Third_Party/LwIP/src/include/lwip/memp.h",
        "Middlewares/Third_Party/LwIP/src/include/lwip/mld6.h",
        "Middlewares/Third_Party/LwIP/src/include/lwip/nd6.h",
        "Middlewares/Third_Party/LwIP/src/include/lwip/netbuf.h",
        "Middlewares/Third_Party/LwIP/src/include/lwip/netdb.h",
        "Middlewares/Third_Party/LwIP/src/include/lwip/netif.h",
        "Middlewares/Third_Party/LwIP/src/include/lwip/netifapi.h",
        "Middlewares/Third_Party/LwIP/src/include/lwip/opt.h",
        "Middlewares/Third_Party/LwIP/src/include/lwip/pbuf.h",
        "Middlewares/Third_Party/LwIP/src/include/lwip/priv/api_msg.h",
        "Middlewares/Third_Party/LwIP/src/include/lwip/priv/mem_priv.h",
        "Middlewares/Third_Party/LwIP/src/include/lwip/priv/memp_priv.h",
        "Middlewares/Third_Party/LwIP/src/include/lwip/priv/memp_std.h",
        "Middlewares/Third_Party/LwIP/src/include/lwip/priv/nd6_priv.h",
        "Middlewares/Third_Party/LwIP/src/include/lwip/priv/raw_priv.h",
        "Middlewares/Third_Party/LwIP/src/include/lwip/priv/sockets_priv.h",
        "Middlewares/Third_Party/LwIP/src/include/lwip/priv/tcp_priv.h",
        "Middlewares/Third_Party/LwIP/src/include/lwip/priv/tcpip_priv.h",
        "Middlewares/Third_Party/LwIP/src/include/lwip/prot/autoip.h",
        "Middlewares/Third_Party/LwIP/src/include/lwip/prot/dhcp.h",
        "Middlewares/Third_Party/LwIP/src/include/lwip/prot/dns.h",
        "Middlewares/Third_Party/LwIP/src/include/lwip/prot/etharp.h",
        "Middlewares/Third_Party/LwIP/src/include/lwip/prot/ethernet.h",
        "Middlewares/Third_Party/LwIP/src/include/lwip/prot/iana.h",
        "Middlewares/Third_Party/LwIP/src/include/lwip/prot/icmp.h",
        "Middlewares/Third_Party/LwIP/src/include/lwip/prot/icmp6.h",
        "Middlewares/Third_Party/LwIP/src/include/lwip/prot/ieee.h",
        "Middlewares/Third_Party/LwIP/src/include/lwip/prot/igmp.h",
        "Middlewares/Third_Party/LwIP/src/include/lwip/prot/ip.h",
        "Middlewares/Third_Party/LwIP/src/include/lwip/prot/ip4.h",
        "Middlewares/Third_Party/LwIP/src/include/lwip/prot/ip6.h",
        "Middlewares/Third_Party/LwIP/src/include/lwip/prot/mld6.h",
        "Middlewares/Third_Party/LwIP/src/include/lwip/prot/nd6.h",
        "Middlewares/Third_Party/LwIP/src/include/lwip/prot/tcp.h",
        "Middlewares/Third_Party/LwIP/src/include/lwip/prot/udp.h",
        "Middlewares/Third_Party/LwIP/src/include/lwip/raw.h",
        "Middlewares/Third_Party/LwIP/src/include/lwip/sio.h",
        "Middlewares/Third_Party/LwIP/src/include/lwip/snmp.h",
        "Middlewares/Third_Party/LwIP/src/include/lwip/sockets.h",
        "Middlewares/Third_Party/LwIP/src/include/lwip/stats.h",
        "Middlewares/Third_Party/LwIP/src/include/lwip/sys.h",
        "Middlewares/Third_Party/LwIP/src/include/lwip/tcp.h",
        "Middlewares/Third_Party/LwIP/src/include/lwip/tcpbase.h",
        "Middlewares/Third_Party/LwIP/src/include/lwip/tcpip.h",
        "Middlewares/Third_Party/LwIP/src/include/lwip/timeouts.h",
        "Middlewares/Third_Party/LwIP/src/include/lwip/udp.h",
        "Middlewares/Third_Party/LwIP/src/include/netif/etharp.h",
        "Middlewares/Third_Party/LwIP/src/include/netif/ethernet.h",
        "Middlewares/Third_Party/LwIP/src/include/netif/ppp/ccp.h",
        "Middlewares/Third_Party/LwIP/src/include/netif/ppp/chap-md5.h",
        "Middlewares/Third_Party/LwIP/src/include/netif/ppp/chap-new.h",
        "Middlewares/Third_Party/LwIP/src/include/netif/ppp/chap_ms.h",
        "Middlewares/Third_Party/LwIP/src/include/netif/ppp/eap.h",
        "Middlewares/Third_Party/LwIP/src/include/netif/ppp/ecp.h",
        "Middlewares/Third_Party/LwIP/src/include/netif/ppp/eui64.h",
        "Middlewares/Third_Party/LwIP/src/include/netif/ppp/fsm.h",
        "Middlewares/Third_Party/LwIP/src/include/netif/ppp/ipcp.h",
        "Middlewares/Third_Party/LwIP/src/include/netif/ppp/ipv6cp.h",
        "Middlewares/Third_Party/LwIP/src/include/netif/ppp/lcp.h",
        "Middlewares/Third_Party/LwIP/src/include/netif/ppp/magic.h",
        "Middlewares/Third_Party/LwIP/src/include/netif/ppp/mppe.h",
        "Middlewares/Third_Party/LwIP/src/include/netif/ppp/polarssl/arc4.h",
        "Middlewares/Third_Party/LwIP/src/include/netif/ppp/polarssl/des.h",
        "Middlewares/Third_Party/LwIP/src/include/netif/ppp/polarssl/md4.h",
        "Middlewares/Third_Party/LwIP/src/include/netif/ppp/polarssl/md5.h",
        "Middlewares/Third_Party/LwIP/src/include/netif/ppp/polarssl/sha1.h",
        "Middlewares/Third_Party/LwIP/src/include/netif/ppp/ppp.h",
        "Middlewares/Third_Party/LwIP/src/include/netif/ppp/ppp_impl.h",
        "Middlewares/Third_Party/LwIP/src/include/netif/ppp/ppp_opts.h",
        "Middlewares/Third_Party/LwIP/src/include/netif/ppp/pppapi.h",
        "Middlewares/Third_Party/LwIP/src/include/netif/ppp/pppcrypt.h",
        "Middlewares/Third_Party/LwIP/src/include/netif/ppp/pppdebug.h",
        "Middlewares/Third_Party/LwIP/src/include/netif/ppp/pppoe.h",
        "Middlewares/Third_Party/LwIP/src/include/netif/ppp/pppol2tp.h",
        "Middlewares/Third_Party/LwIP/src/include/netif/ppp/pppos.h",
        "Middlewares/Third_Party/LwIP/src/include/netif/ppp/upap.h",
        "Middlewares/Third_Party/LwIP/src/include/netif/ppp/vj.h",
        "Middlewares/Third_Party/LwIP/system/arch/bpstruct.h",
        "Middlewares/Third_Party/LwIP/system/arch/cc.h",
        "Middlewares/Third_Party/LwIP/system/arch/cpu.h",
        "Middlewares/Third_Party/LwIP/system/arch/epstruct.h",
        "Middlewares/Third_Party/LwIP/system/arch/init.h",
        "Middlewares/Third_Party/LwIP/system/arch/lib.h",
        "Middlewares/Third_Party/LwIP/system/arch/perf.h",
        "Middlewares/Third_Party/LwIP/system/arch/sys_arch.h",
        "ethernetif.h",
        "lwip.h",
        "lwipopts.h",
        "main.h",
        "stm32h7xx_hal_conf.h",
    ],
    copts = [
        # We don't want to mark warnings as errors for 3rd party code
        "-Wno-error",
    ],
    defines = [
        "STM32H743xx",
    ],
    includes = [
        "./",
        "Drivers/BSP/Components/lan8742",
        "Middlewares/Third_Party/LwIP/src/include",
        "Middlewares/Third_Party/LwIP/system",
        "Middlewares/Third_Party/LwIP/system/arch",
    ],
    restricted_to = ["//cc_toolchain:stm32h7"],
    deps = [
        ":hal",
        ":rtos",
    ],
    alwayslink = True,
)

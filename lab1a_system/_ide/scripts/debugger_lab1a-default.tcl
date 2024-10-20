# Usage with Vitis IDE:
# In Vitis IDE create a Single Application Debug launch configuration,
# change the debug type to 'Attach to running target' and provide this 
# tcl script in 'Execute Script' option.
# Path of this script: /home/parallels/workspace/lab1a_system/_ide/scripts/debugger_lab1a-default.tcl
# 
# 
# Usage with xsct:
# To debug using xsct, launch xsct and run below command
# source /home/parallels/workspace/lab1a_system/_ide/scripts/debugger_lab1a-default.tcl
# 
connect -url tcp:127.0.0.1:3121
targets -set -filter {jtag_cable_name =~ "Digilent Nexys A7 -100T 210292BCFA4EA" && level==0 && jtag_device_ctx=="jsn-Nexys A7 -100T-210292BCFA4EA-13631093-0"}
fpga -file /home/parallels/workspace/lab1a/_ide/bitstream/download.bit
targets -set -nocase -filter {name =~ "*microblaze*#0" && bscan=="USER2" }
loadhw -hw /home/parallels/workspace/153aHardware/export/153aHardware/hw/design_1_wrapper.xsa -regs
configparams mdm-detect-bscan-mask 2
targets -set -nocase -filter {name =~ "*microblaze*#0" && bscan=="USER2" }
rst -system
after 3000
targets -set -nocase -filter {name =~ "*microblaze*#0" && bscan=="USER2" }
dow /home/parallels/workspace/lab1a/Debug/lab1a.elf
targets -set -nocase -filter {name =~ "*microblaze*#0" && bscan=="USER2" }
con

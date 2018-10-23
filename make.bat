del *.rel *.ihx *.hex
sdcc.exe --model-medium --opt-code-size -c modbus.c -o modbus.rel
sdcc.exe --model-medium --opt-code-size -c test.c -o test.rel
sdcc.exe --model-medium test.rel modbus.rel -o test.ihx
packihx test.ihx > test.hex
type test.map |findstr CODE
pause

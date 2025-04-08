# Zephyr Getting Started

## Zephyr Vanilla

### Installation
- Just follow along this official zephyr article, I use the windows variants: https://docs.zephyrproject.org/latest/develop/getting_started/index.html

### Setup Environment
- Command Prompt
```bash
set ZEPHYR_BASE=%HOMEPATH%\zephyrproject\zephyr & call "%HOMEPATH%\zephyrproject\.venv\Scripts\activate.bat" & west zephyr-export
```
- Powershell
```powershell
$env:ZEPHYR_BASE = "$env:HOMEPATH\zephyrproject\zephyr"; & "$env:HOMEPATH\zephyrproject\.venv\Scripts\Activate.ps1"; west zephyr-export
```

### Create Project
- Create projects within `%HOMEPATH%\zephyrproject\projects`

### Build
```bash
west build -p always -b blackpill_f411ce -d build_blackpill_f411ce
west build -p always -b esp32s3_devkitc/esp32s3/procpu -d build_esp32s3_devkitc
west build -p always -b esp32_devkitc_wroom/esp32/procpu # should consider to just use `-d build/` default directory, or else will not be able to use `west espressif monitor`, instead use miniterm
```

### Flash
```bash
west flash
west flash --build-dir build_esp32_devkitc_wroom --esp-device COM3
```

### Monitor
```bash
west monitor -p COM3
```

Espressif Systems
```bash
west espressif monitor --port COM3
west espressif monitor -p COM3

# alternatively for espressif systems
python -m serial.tools.miniterm COM3 115200
```

Arguments for espressif monitor, aka idf_monitor (under the hood)
```bash
# verbose one
usage: idf_monitor - a serial output monitor for esp-idf [-h] [--port PORT] [--disable-address-decoding] [--baud BAUD] [--make MAKE] [--encrypted] [--toolchain-prefix TOOLCHAIN_PREFIX] [--eol {CR,LF,CRLF}] [--print_filter PRINT_FILTER] [--decode-coredumps {info,disable}] [--decode-panic {backtrace,disable}] [--target TARGET] [--revision REVISION] [--ws WS] [--timestamps] [--timestamp-format TIMESTAMP_FORMAT] elf_file

# shorter one
west espressif [-h] [-b BAUD] [-p PORT] [-e ELF] [-n EOL] [-d] {monitor}
```

### Issues

## Zephyr nRF Connect Extension

### Issues
- Cannot build configuration for board targets other than from nRF (failed on ESP32, Blackpill, Bluepill)
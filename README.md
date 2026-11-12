# TB IC100-S (2026 Mac)

A model of the **H/H IC100-S** guitar amplifier head as **CLAP, VST3 and AU** plugins for current
Macs: universal (Apple Silicon + Intel), macOS 11 and later, for Reaper, FL Studio, Logic and
other hosts. Non-commercial, personal use.

This is the same circuit model, panel and presets as the Mountain Lion VST
([TB-IC100S-Mountain-Lion](https://github.com/tonybuzzcock/TB-IC100S-Mountain-Lion)); the test
suite checks the output matches it sample for sample. See that repo's README for what is
modelled from the *IC100-S Circuit Diagram* (in `Docs/`) and which values are estimates.

## The panel

| Upper band | Channel 1: **Sustain, Presence, Treble, Bass, Volume** — Channel 2: **Brilliance, Treble, Bass, Volume** |
|---|---|
| Switch row | **Sustain** slide, **Ch 1 Input** Normal/Bright rocker, **Ch 1** on rocker, **Studio/Stage** slide, **Ch 2 Input** Normal/Bright rocker, **Ch 2** on rocker, red **Mains** rocker |
| Plugin strip | **Speaker** (miked 2x12 or speaker terminals), **Input** ±12 dB, **Output** ±24 dB, 8 presets, readout |

Every switch lights up on its engaged side. **Mains** off passes the dry signal, time-aligned.

## Download and install

1. Repo → **Actions** → newest green run → Artifacts → **TB-IC100S-mac** → download and unzip
   (twice: the artifact zip holds `TB-IC100S-mac.zip`).
2. Follow **INSTALL.txt** inside: copy the plugins into `/Library/Audio/Plug-Ins/` (VST3, Components,
   CLAP), then in Terminal, one line at a time:

        cd /Library/Audio/Plug-Ins
        ls */ | grep -i ic100
        sudo xattr -cr */"TB IC100-S".*
        sudo codesign --force --deep --sign - */"TB IC100-S".*
        killall -9 AudioComponentRegistrar

3. In Reaper: Settings > Plug-ins > VST and CLAP > **Clear cache/re-scan**.

## Build

    cmake -B build -DCMAKE_BUILD_TYPE=Release
    cmake --build build -j4

clap-wrapper (v0.17.0) and the CLAP, VST3 and AudioUnit SDKs are fetched at configure time.
On Linux this builds the CLAP and the tests (`preset_test`, `ic100s_test`, `clap_host_test`).
GitHub Actions builds all three formats, checks they are universal with a minimum of macOS 11,
runs the tests, the panel test, auval, clap-validator and pluginval, and publishes panel
screenshots to the `gui-preview` branch.

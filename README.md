# LyricsMan

**A simple software for beautiful lyrics in your terminal with configs**

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![Platform](https://img.shields.io/badge/platform-Windows%20%7C%20Linux%20%7C%20Android-blue)](https://github.com/artikruss777/lyricsman)

---

## 🎵 About

**LyricsMan** is a lightweight, cross-platform terminal application that displays lyrics with beautiful typing animations. Inspired by those satisfying TikTok lyric videos, this tool brings the same aesthetic experience right into your terminal — no programming knowledge required!

Whether you're a content creator, a karaoke enthusiast, or just someone who loves watching lyrics appear letter by letter, LyricsMan is for you.

---

## ✨ Features

- 🎬 **Typing animation** — each letter appears with customizable delay
- 🎨 **Color support** — red, green, yellow, blue, and default terminal colors
- ⏱️ **Configurable timing** — set delay between letters and pause after each line
- 📄 **Simple config system** — no programming skills needed, just plain text
- 💻 **Cross-platform** — works on Windows, Linux, macOS, and even Android (Termux)
- 🪶 **Minimal & fast** — written in pure C with no external dependencies

---

## 📸 Demo

```
==================[LyricsMan]==================
- by artikruss777
- v1.0.0
Enter path to config: lyrics.txt
===============================================

🎤 Rolling in the deep...
(animated typing effect with colors)
```

---

## 🚀 Installation

### Windows (MSYS2/MinGW GCC)
```bash
git clone https://github.com/artikruss777/lyricsman.git
cd lyricsman
gcc lyricsman.c -o lyricsman.exe
./lyricsman.exe
```

### Linux / macOS
```bash
git clone https://github.com/artikruss777/lyricsman.git
cd lyricsman
gcc lyricsman.c -o lyricsman
./lyricsman
```

### Android (Termux)
```bash
pkg install gcc
git clone https://github.com/artikruss777/lyricsman.git
cd lyricsman
gcc lyricsman.c -o lyricsman
./lyricsman
```

---

## 📝 Configuration Guide

Create a `.txt` file (e.g., `song.txt`) with commands separated by new lines. Each command uses the pipe symbol `|` to separate arguments.

### Available Commands

#### 1. `print` — Animated text output
```
print|text|typing_delay|pause_after|newline|color
```

| Argument | Description | Example |
|----------|-------------|---------|
| `text` | The text to display | `Hello world!` |
| `typing_delay` | Seconds between each letter (decimal) | `0.05` |
| `pause_after` | Seconds to pause after finishing | `1` |
| `newline` | Add newline after? (`true`/`false`) | `true` |
| `color` | Text color (`RED`/`GREEN`/`YELLOW`/`BLUE`/`RESET`) | `RED` |

#### 2. `rawprint` — Instant text output
```
rawprint|text
```

#### 3. `wait` — Pause execution
```
wait|seconds
```

---

## 🎮 Example Config

Create `mysong.txt`:

```
print|Hello World!|0.05|0.5|true|GREEN
wait|1
rawprint|Goodbye World!
```

---

## 🎯 Usage

### Method 1: Interactive mode
```bash
./lyricsman
```
Then enter your config file path when prompted.

### Method 2: Direct file argument
```bash
./lyricsman mysong.txt
```

---

## 🧪 Tested Platforms

| Platform | Compiler | Status |
|----------|----------|--------|
| Windows 11 | MSYS2 GCC | ✅ Working |
| Android 13+ | Termux GCC | ✅ Working |

---

## 🤝 Contributing

Contributions are welcome! Feel free to:
- Report bugs
- Suggest features
- Submit pull requests

---

## 📞 Contact

**Developer:** artikruss777  
**Telegram:** [t.me/artikruss777](https://t.me/artikruss777)

---

## 📄 License

MIT License — free for personal and commercial use. See [LICENSE](LICENSE) file for details.

---

## 🙏 Acknowledgments

- Inspired by TikTok lyric video trends
- Built for terminal enthusiasts everywhere
- Special thanks to the open-source community

---

**Made with ❤️ and C**
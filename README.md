# 🔐 密码生成器 (Qt5图形界面版)

一个使用Qt5开发的现代化、安全、跨平台的密码生成器工具。

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![Platform](https://img.shields.io/badge/platform-Linux-blue.svg)](https://github.com)
[![Qt5](https://img.shields.io/badge/Qt-5.6+-green.svg)](https://www.qt.io/)

## ✨ 功能特点

- 🎨 **现代化GUI** - 使用Qt5开发的简洁美观的图形界面
- ✂️ **一键复制** - 自动复制到剪切板，无需显示密码
- 📏 **长度可调** - 支持8-128位密码
- 🔤 **字符可选** - 支持多种字符类型组合：
  - 大写字母 (A-Z)
  - 小写字母 (a-z)
  - 数字 (0-9)
  - 特殊字符 (!@#$%^&*等)
- 🔒 **安全随机** - 使用Qt5的QRandomGenerator生成密码
- 🌍 **跨平台** - 支持Linux、Windows、macOS

## 📸 界面预览

```
┌─────────────────────────────┐
│      🔐 密码生成器          │
├─────────────────────────────┤
│  密码长度: [16] (8-128)    │
├─────────────────────────────┤
│  ☐ 大写字母 (A-Z)          │
│  ☑ 小写字母 (a-z)          │
│  ☑ 数字 (0-9)              │
│  ☑ 特殊字符 (!@#$%...)     │
├─────────────────────────────┤
│  [  生成并复制到剪切板  ]   │
└─────────────────────────────┘
```

## 🚀 快速开始

### 系统要求

- Qt5 (>= 5.6)
- CMake (>= 3.10)
- C++11 编译器
- Linux/Windows/macOS

### 编译安装

```bash
# 克隆仓库
git clone https://github.com/yourusername/passwordgenerator.git
cd passwordgenerator

# 创建构建目录
mkdir build && cd build

# 编译
cmake ..
make

# 运行
./passwordgenerator
```

### 安装依赖

**Ubuntu/Debian:**
```bash
sudo apt-get install qtbase5-dev cmake build-essential
```

**Fedora:**
```bash
sudo dnf install qt5-qtbase-devel cmake gcc-c++
```

**Arch Linux:**
```bash
sudo pacman -S qt5-base cmake gcc
```

**macOS (Homebrew):**
```bash
brew install qt5 cmake
```

## 📦 安装包

### Debian/Ubuntu (.deb)

```bash
sudo dpkg -i passwordgenerator_1.0.0_amd64.deb
```

如遇依赖问题：
```bash
sudo apt-get install -f
```

## 🎯 使用方法

1. 启动程序
2. 设置密码长度（滑块或输入框）
3. 选择需要的字符类型
4. 点击"生成并复制到剪切板"按钮
5. 密码自动复制，直接粘贴使用！

## 📂 项目结构

```
passwordgenerator/
├── CMakeLists.txt              # CMake构建配置
├── README.md                   # 项目说明
├── LICENSE                     # MIT许可证
├── main.cpp                    # 程序入口
├── passwordgenerator.h         # 主窗口类声明
├── passwordgenerator.cpp       # 主窗口类实现
├── icons/                      # 图标资源
│   └── hicolor/               # 多尺寸图标
├── debian_pkg/                 # Debian打包配置
└── build/                      # 编译输出目录（不提交）
```

## 🤝 贡献指南

欢迎提交Issue和Pull Request！

1. Fork 本仓库
2. 创建特性分支 (`git checkout -b feature/AmazingFeature`)
3. 提交更改 (`git commit -m 'Add some AmazingFeature'`)
4. 推送到分支 (`git push origin feature/AmazingFeature`)
5. 创建Pull Request

## 📄 许可证

本项目采用 MIT 许可证 - 详见 [LICENSE](LICENSE) 文件

## 🔧 开发说明

### 代码规范

- 遵循C++11标准
- 使用Qt信号槽机制
- 遵守Qt编码规范
- 代码注释完整

### 调试构建

```bash
cmake -DCMAKE_BUILD_TYPE=Debug ..
make
```

### 发布构建

```bash
cmake -DCMAKE_BUILD_TYPE=Release ..
make
```

## 🐛 常见问题

**Q: 编译报错"Could not find Qt5"？**  
A: 确保安装了qtbase5-dev包

**Q: 图标不显示？**  
A: 运行 `gtk-update-icon-cache -f -t /usr/share/icons/hicolor`

**Q: 如何卸载？**  
A: `sudo dpkg -r passwordgenerator`

## 👨‍💻 作者

**AERKEALENN** - lqwallen@163.com

## 🙏 致谢

- Qt框架
- ImageMagick（图标处理）
- CMake社区

---

**如果这个项目对你有帮助，请给我们一个⭐！**


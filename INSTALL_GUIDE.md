# 密码生成器 - 安装指南

## 📦 .deb安装包信息

**文件名:** `passwordgenerator_1.0.0_amd64.deb`  
**包大小:** ~1.5MB  
**系统要求:** Ubuntu/Debian 64位系统

## ✨ 实现的功能

### 1. ✅ 自动创建系统启动菜单快捷方式
安装后，程序会自动：
- 在系统应用程序菜单中创建快捷方式
- 支持搜索功能（通过输入"密码生成器"或"Password Generator"）
- 分类到"工具"(Utility)或"系统"(System)类别

### 2. ✅ 使用指定图标
- 原图标来源: `/home/allen/下载/image_681940627684567.png`
- 白色背景已转换为透明背景
- 提供多种尺寸的图标支持（16x16, 24x24, 32x32, 48x48, 64x64, 128x128, 256x256）
- 自动适应不同分辨率的显示

### 3. ✅ 图标复制到软件安装目录
- 所有图标文件已复制到: `/usr/share/icons/`
- 包括完整的hicolor图标主题结构
- 安装后图标会在整个系统中可见

### 4. ✅ 透明背景图标处理
- 原图标的白色背景已移除
- 保留原始图像内容的清晰度
- 支持任何背景色的任务栏和菜单

## 🚀 安装方法

### 方法一：使用dpkg命令（推荐）

```bash
sudo dpkg -i passwordgenerator_1.0.0_amd64.deb
```

如果提示缺少依赖，执行：
```bash
sudo apt-get install -f
```

### 方法二：使用软件中心

1. 双击 `.deb` 文件
2. 点击"安装"按钮
3. 输入管理员密码
4. 等待安装完成

## 🎯 安装后检查

### 检查程序是否安装成功：
```bash
which passwordgenerator
```

### 检查桌面快捷方式是否创建：
```bash
ls -la /usr/share/applications/passwordgenerator.desktop
```

### 检查图标是否安装：
```bash
ls -la /usr/share/icons/hicolor/48x48/apps/passwordgenerator.png
```

### 在应用菜单中查找：
- 搜索"密码生成器"
- 或在"工具"类别中查找

## 🖥️ 启动程序

安装完成后，可以通过以下方式启动：

1. **应用菜单**: 在系统应用菜单中搜索"密码生成器"或"Password Generator"
2. **终端命令**: 在终端中输入 `passwordgenerator`
3. **桌面快捷方式**: 如果创建了桌面快捷方式，双击启动

## 🗑️ 卸载方法

```bash
sudo dpkg -r passwordgenerator
```

或者在软件中心中点击"卸载"

## 🔧 安装过程说明

### 自动化脚本

安装包包含两个自动化脚本：

1. **postinst** - 安装后脚本
   - 自动更新图标缓存
   - 注册桌面快捷方式
   - 确保图标在系统中可见

2. **prerm** - 卸载前脚本
   - 清理相关配置
   - 更新桌面数据库

### 依赖项

安装时会自动检查并安装以下依赖：
- libc6 (>= 2.17)
- libqt5widgets5 (>= 5.6.0)
- libqt5gui5 (>= 5.6.0)
- libqt5core5a (>= 5.6.0)
- libgcc-s1 (>= 3.0)
- libstdc++6 (>= 6)
- libxcb-xinerama0

## ❓ 常见问题

### Q: 安装后图标不显示？
A: 运行以下命令更新图标缓存：
```bash
sudo gtk-update-icon-cache -f -t /usr/share/icons/hicolor
```

### Q: 在菜单中找不到程序？
A: 尝试注销并重新登录，或重启系统。

### Q: 提示缺少依赖？
A: 执行：
```bash
sudo apt-get update
sudo apt-get install -f
```

## 📁 安装包结构

```
/
├── usr/
│   ├── bin/
│   │   └── passwordgenerator          # 可执行文件
│   └── share/
│       ├── applications/
│       │   └── passwordgenerator.desktop  # 桌面快捷方式配置
│       └── icons/
│           └── hicolor/
│               ├── 16x16/apps/passwordgenerator.png
│               ├── 24x24/apps/passwordgenerator.png
│               ├── 32x32/apps/passwordgenerator.png
│               ├── 48x48/apps/passwordgenerator.png
│               ├── 64x64/apps/passwordgenerator.png
│               ├── 128x128/apps/passwordgenerator.png
│               └── 256x256/apps/passwordgenerator.png
└── DEBIAN/
    ├── control                         # 包控制信息
    ├── postinst                        # 安装后脚本
    └── prerm                           # 卸载前脚本
```

## 🎉 享受使用！

安装完成后，你就可以在系统的应用菜单中找到并启动密码生成器了！它会自动使用你指定的图标，并具有透明背景效果。

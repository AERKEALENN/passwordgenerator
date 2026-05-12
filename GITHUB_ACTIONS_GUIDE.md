# 🚀 GitHub Actions CI/CD 自动构建指南

## ✅ 已配置的功能

本项目已配置 GitHub Actions 工作流，可以自动为三个平台构建安装包：

- ✅ **Linux** - 生成 .deb 安装包
- ✅ **Windows** - 生成 .exe 可执行文件
- ✅ **macOS** - 生成 .app 应用程序包

---

## 🔄 工作流程

### 触发条件

1. **推送到 main 分支** - 自动构建（不创建Release）
2. **推送 tag** (如 `v1.0.0`) - 自动构建并创建 Release
3. **Pull Request** - 自动构建测试

### 自动执行的任务

1. 安装 Qt5 开发环境
2. 使用 CMake 配置项目
3. 编译代码
4. 为各平台打包
5. 上传到 Artifacts（临时存储）
6. 如果是 tag 发布，自动创建 Release

---

## 📦 发布新版本步骤

### 方法1：使用 GitHub 网页（推荐）

1. 在本地修改代码
2. 推送更改到 main
3. 创建 Release：
   - 进入仓库页面
   - 点击 "Releases" → "Draft a new release"
   - 填写版本号（如 `v1.0.0`）
   - 点击 "Publish release"

### 方法2：使用 Git 命令行

```bash
# 1. 修改代码后提交
git add .
git commit -m "Update features"

# 2. 推送代码
git push origin main

# 3. 创建并推送 tag
git tag v1.0.0
git push origin v1.0.0

# 这会自动触发构建并创建 Release！
```

---

## 📥 下载安装包

### 方式1：通过 Actions 页面

1. 进入仓库 → Actions
2. 选择最新的 workflow run
3. 滚动到底部 "Artifacts"
4. 下载对应的平台包

### 方式2：通过 Release 页面

1. 进入仓库 → Releases
2. 点击最新的 Release
3. 在 "Assets" 中下载对应平台的安装包

---

## ⚙️ 工作流详情

### 构建矩阵

| 平台 | 系统 | 架构 | 输出文件 |
|------|------|------|---------|
| Linux | Ubuntu Latest | amd64 | .deb |
| Windows | Windows Latest | x64 | .exe |
| macOS | macOS Latest | x64/arm64 | .tar.gz |

### 构建时间估算

- Linux: ~5-10 分钟
- Windows: ~10-15 分钟
- macOS: ~10-15 分钟
- 总计: ~15-25 分钟

---

## 🔧 故障排除

### 构建失败

1. **Qt5 安装失败**
   - 检查 Qt5 包名是否正确
   - 可能需要更新包管理器

2. **CMake 配置失败**
   - 检查 CMakeLists.txt 语法
   - 确认 Qt5 路径正确

3. **编译错误**
   - 查看构建日志
   - 检查代码兼容性

### Release 未创建

- 确认是 tag 推送，不是分支推送
- 检查 tag 格式是否为 `v*`（如 v1.0.0）
- 确认 GitHub Token 权限足够

---

## 📊 查看构建状态

1. 进入 GitHub 仓库
2. 点击 "Actions" 标签
3. 查看所有 workflow runs
4. 点击具体 run 查看详细日志

---

## 🛡️ 安全说明

- 所有构建在 GitHub 隔离环境中运行
- 不访问你的本地文件
- GitHub Token 自动提供，无需手动配置
- Artifacts 仅保留 30 天

---

## 📝 注意事项

1. **免费额度**
   - GitHub 免费账户每月 2000 分钟构建时间
   - 开源项目无限制

2. **首次构建**
   - 首次推送 tag 可能需要更长时间
   - 需要下载和缓存 Qt5

3. **版本号**
   - 建议遵循语义化版本 (SemVer)
   - 格式: `v主版本.次版本.补丁版本`
   - 例如: v1.0.0, v1.2.3, v2.0.0-beta

---

## 🎯 下一步

1. ✅ 配置文件已创建
2. ⏳ 推送到 GitHub
3. ⏳ 在 GitHub 查看 Actions
4. ⏳ 创建第一个 Release

---

## 📚 相关资源

- [GitHub Actions 文档](https://docs.github.com/cn/actions)
- [Qt5 下载](https://www.qt.io/download)
- [CMake 教程](https://cmake.org/tutorial/)

---

**有问题？** 查看 Actions 页面的构建日志，或提交 Issue！

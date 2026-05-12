# 🚀 GitHub 配置指南

## ✅ 本地Git仓库已初始化

密码生成器项目已经成功配置了Git：

```bash
📍 位置: /home/allen/Desktop/项目/passwordgenerator
🌿 分支: main
📝 提交: 5bf9845 - Initial commit
```

---

## 📋 步骤1：在GitHub上创建新仓库

### 方法A：通过网页创建（推荐）

1. **登录GitHub**
   - 访问 https://github.com
   - 点击右上角的 "+" 图标
   - 选择 "New repository"

2. **配置仓库**
   - **Repository name**: `passwordgenerator`
   - **Description**: `🔐 A modern Qt5-based password generator with GUI`
   - **Public/Private**: 选择 Public（公开）或 Private（私有）
   - **不要勾选** "Add a README file"（项目已有）
   - **不要勾选** "Add .gitignore"（项目已有）

3. **创建仓库**
   - 点击 "Create repository"

---

## 🔐 步骤2：创建Personal Access Token

### 为什么需要Token？

GitHub不再支持密码认证，需要使用Personal Access Token (PAT)来推送代码。

### 创建Token步骤：

1. **登录GitHub**
   - 访问 https://github.com
   - 点击右上角头像 → **Settings**

2. **导航到开发者设置**
   - 左侧菜单点击 "Developer settings"
   - 选择 "Personal access tokens" → "Tokens (classic)"

3. **生成新Token**
   - 点击 "Generate new token"
   - 点击 "Generate new token (classic)"

4. **配置Token**
   - **Note**: `passwordgenerator-repo-access`
   - **Expiration**: 选择过期时间（如 30 days / 90 days）
   - **Scopes**: 勾选以下权限：
     - ✅ `repo` - 完全控制私有仓库
     - ✅ `workflow` - 更新GitHub Actions（可选）

5. **生成Token**
   - 点击 "Generate token"
   - **⚠️ 重要**：立即复制Token并保存！Token只显示一次

---

## 🔗 步骤3：连接本地仓库到GitHub

### 添加远程仓库

在终端中执行：

```bash
cd /home/allen/Desktop/项目/passwordgenerator

# 添加远程仓库（将 YOUR_USERNAME 替换为你的GitHub用户名）
git remote add origin https://github.com/YOUR_USERNAME/passwordgenerator.git

# 验证远程仓库
git remote -v
```

**预期输出：**
```
origin  https://github.com/YOUR_USERNAME/passwordgenerator.git (fetch)
origin  https://github.com/YOUR_USERNAME/passwordgenerator.git (push)
```

---

## 📤 步骤4：推送代码到GitHub

### 首次推送

```bash
# 推送到GitHub
git push -u origin main
```

**系统会提示输入凭证：**

- **Username**: 你的GitHub用户名
- **Password**: **粘贴你的Personal Access Token**（不是密码！）

### 验证推送成功

1. 刷新GitHub仓库页面
2. 应该能看到所有文件
3. README.md会显示在首页

---

## 🔄 步骤5：常用Git命令

### 查看状态
```bash
git status
```

### 查看历史
```bash
git log --oneline
```

### 创建新分支
```bash
git checkout -b feature/new-feature
```

### 提交更改
```bash
git add .
git commit -m "描述你的更改"
```

### 推送到远程
```bash
git push origin main
```

### 更新本地代码
```bash
git pull origin main
```

---

## 🛡️ 安全建议

### 1. 保护你的Token

- ✅ **不要**将Token提交到Git
- ✅ 使用Git Credential Manager存储Token
- ✅ Token过期前及时续期

### 2. 配置Git Credential Helper（推荐）

```bash
# 配置Git记住凭证（15分钟）
git config --global credential.helper cache

# 或配置长期保存（不推荐在多人共用电脑）
git config --global credential.helper store
```

### 3. 定期更新Token

- 设置提醒在Token过期前更新
- 过期后需要重新生成

---

## 🎯 下一步

1. ✅ 在GitHub创建仓库
2. ✅ 生成Personal Access Token
3. ✅ 添加远程仓库
4. ✅ 推送代码
5. ⬜ 开始协作开发

---

## ❓ 常见问题

### Q: 推送时认证失败？
A: 
- 确保使用的是Personal Access Token而非密码
- 检查Token是否过期
- 确认Token有`repo`权限

### Q: 如何修改远程仓库地址？
A:
```bash
git remote set-url origin NEW_URL
```

### Q: 如何查看所有远程仓库？
A:
```bash
git remote -v
```

### Q: 推送被拒绝？
A:
```bash
# 如果远程有更新，先拉取合并
git pull origin main --allow-unrelated-histories

# 然后再推送
git push -u origin main
```

---

## 📚 相关资源

- [GitHub文档](https://docs.github.com/)
- [Git教程](https://git-scm.com/doc)
- [创建Personal Access Token](https://github.com/settings/tokens/new)

---

## 🎉 恭喜！

你的密码生成器项目现在可以通过Git进行版本控制了，并且已经准备好上传到GitHub！

**继续下一步：**
1. 打开 https://github.com/new
2. 创建名为 `passwordgenerator` 的新仓库
3. 按照上面的指南配置Token
4. 推送代码

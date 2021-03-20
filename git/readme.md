# git

## git log

```bash
# 查找有删除信息的日志，并显示具体的日志信息。
git log --diff-filter=D --summary
```

## git rm

```bash
# 删除指定路径文件的记录。
git rm --cached --ignore-unmatch /file/path
```

## git restore

```bash
# 去掉 git add 添加的记录。
# 只对 git add 但是没有 git commit 的记录有效。
git restore --staged /file_or_dir/path

# 没有被 git add 的文件会回退修改的内容。
# 但是仅限文件修改，算是弱化版的 git checkout .
# 只对没有 git add 的文件有效。
git restore /file_or_dir/path
```

## git checkout

```bash
# 撤销修改，还没有 git add 。
git checkout /dir/path

# 撤销修改指定文件。
git checkout -- /file/path
```

## git filter-branch

过滤分支，名不副实，这个命令是会修改记录的。并非检索信息，命名有误导性。该命令选定遍历器后会遍历所有分支。

## 删除分支

```bash
# 删除本地分支
git branch -D <name>

# 删除远程分支
git push <remote> --delete <name>
```

## 子模块 submodule

```bash
# 添加子模块
git submodule add <url> <name>
```

## 远程分支

```bash
# 添加远程库
git remote add <remote> <url>

# 重命名
git remote rename <name> <newname>

# 拉取远程分支到本地分支
git pull <remote> <remote_name>:<local_name>

# 推送本地分支到远程分支
git push <remote> <local_name>:<remote_name>
```

## stash 暂存命令

```bash
# 查看暂存列表
git stash list

# 把 git add 保存的暂存起来，内容在当前分支撤回。
git stash

# 添加备注信息
git stash -m "your message content."

# 把暂存的修改放出，最近一条。
git stash pop

# 指定索引弹出，可以 git stash list 看到索引
git stash pop 1

# 查看改动，最近一条
git stash show 

# 查看改动，指定索引
git stash show 1

# 应用，类似pop 但是不删除
git stash apply

# 指定索引
git stash apply 1

# 删除
git stash drop

# 删除指定
git stash drop 1

# 清除所有暂存
git stash clear
```

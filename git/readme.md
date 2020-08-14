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

## git filter-branch

过滤分支，名不副实，这个命令是会修改记录的。并非检索信息，命名有误导性。该命令选定遍历器后会遍历所有分支。

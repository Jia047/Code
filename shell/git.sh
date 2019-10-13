echo “请输入git仓库路径”
read git_path
git add $git_path
echo “请输入提交信息”
read cm
git commit -m $cm

git push orign master

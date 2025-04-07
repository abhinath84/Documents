# Introduction

Git, gitlab, github related stuff.

## Add new local repo in remote

- create a new repo in remote github
- initialize your local project into git repo
```sh
git init
```
- Add local project to git repo
```sh
git add .
```
- commit local project to git repo
```sh
git commit -ma "<commit comment>"
```
- add remote repo
```sh
git remote add origin <remote git repo link>
```
- push local project to remote git repo
```sh
git push -u origin master
```
- you are done!

## Brach related commands

- Check existing branches
```sh
git branch
```
- Create a new branch
```sh
git branch <branch_name>
          OR
git checkout -b <branch_name>
```
- Checkout to new branch
```sh
git checkout <branch_name>
```
- Push new branch changes to github/gitlab
```sh
git push origin <branch_name>
```
- Merege changes to Master branch
```sh
git checkout master
git merge <branch_name>
git push origin master
```
- Revert changes
```sh
git checkout -- <file_name with abstract path>
```

## Command Line Instructions

- Git global setup
```sh
git config --global user.name "Abhishek Nath"
git config --global user.email "abhi.nath@outlook.com"
```
- Clone remote repo to local PC
```sh
git clone https://gitlab.com/abhinath84/project_management_20.git
cd project_management_20
touch README.md
git add README.md
git commit -m "add README"
git push -u origin master
```
- Intialize exsiting project with `git` & setup remote repo as well
```sh
cd existing_folder
git init
git remote add origin https://gitlab.com/abhinath84/project_management_20.git
git add .
git commit
git push -u origin master
```

## Update remote repository

Update existing git repository by local project:

- create clone of the remote git repo if it not present locally.
```sh
git clone <http of remote repo>
```
- add remote repo in local project
```sh
git remote add origin <remote git repo link>
```

> If you already create a clone of remote repo then no need to execute above command.

- If you have clone of remote project then just pull the data from remote repo
```sh
git pull origin master
```
> Duplicate entry. No need to call above command.

- update local project with desire information by commiting your changes in local repo
```sh
git commit -am "<commit comment>"
```
- Push them into remote repo
```sh
git push origin master
```
- you are done!

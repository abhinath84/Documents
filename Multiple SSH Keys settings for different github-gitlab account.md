## steps:
- create ssh key for each account.
```
ssh-keygen -t rsa -C "<comment>" -f "<ssh-key-file-name>"
```
- open github/gitlab web-page and create 'add new key' & paste content of "<ssh-key-file-name>.pub".
- create "~/.ssh/config" file. (if not present)
- add HOST entry for above ssh key.
sample:
```
  # github-personal
  Host github.com
    HostName github.com
    User git
    IdentityFile ~/.ssh/github-personal
```
- repeate above steps for each newly created key.

## References:

- https://gist.github.com/rahularity/86da20fe3858e6b311de068201d279e3
- https://gist.github.com/jexchan/2351996
- https://www.youtube.com/watch?v=N2hMGEeYR7c

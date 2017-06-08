Using Git
#########

..  warning::

    Some commands shown here are specific to Linux/Mac.

Global Settings
***************

Related Setup: https://gist.github.com/hofmannsven/6814278

Related Pro Tips: https://ochronus.com/git-tips-from-the-trenches/

Interactive Beginners Tutorial: http://try.github.io/


Reminder
********

Press `minus + shift + s` and `return` to chop/fold long lines!

Show folder content: `ls -la`


Setup
*****

See where Git is located:

..  code-block:: bash

    which git

Get the version of Git:

..  code-block:: bash

    git --version

Create an alias (shortcut) for `git status`:

..  code-block:: bash

    git config --global alias.st status


Help
****

Help:

..  code-block:: bash

    git help


General
*******

Initialize Git:

..  code-block:: bash

    git init

Get everything ready to commit:

..  code-block:: bash

    git add .

Get custom file ready to commit:

..  code-block:: bash

    git add index.html

Commit changes:

..  code-block:: bash

    git commit -m "Message"

Add and commit in one step:

..  code-block:: bash

    git commit -am "Message"

Remove files from Git:

..  code-block:: bash

    git rm index.html

Update all changes:

..  code-block:: bash

    git add -u

Remove file but do not track anymore:

..  code-block:: bash

    git rm --cached index.html

Move or rename files:

..  code-block:: bash

    git mv index.html dir/index_new.html

Undo modifications (restore files from latest commited version):

..  code-block:: bash

    git checkout -- index.html

Restore file from a custom commit (in current branch):

..  code-block:: bash

    git checkout 6eb715d -- index.html


Reset
*****

Go back to commit:

..  code-block:: bash

    git revert 073791e7dd71b90daa853b2c5acc2c925f02dbc6

Soft reset (move HEAD only; neither staging nor working dir is changed):

..  code-block:: bash

git reset --soft 073791e7dd71b90daa853b2c5acc2c925f02dbc6

Mixed reset (move HEAD and change staging to match repo; does not affect working dir):

..  code-block:: bash

    git reset --mixed 073791e7dd71b90daa853b2c5acc2c925f02dbc6

Hard reset (move HEAD and change staging dir and working dir to match repo):

..  code-block:: bash

git reset --hard 073791e7dd71b90daa853b2c5acc2c925f02dbc6

Update & Delete
***************

Test-Delete untracked files:

..  code-block:: bash

    git clean -n

Delete untracked files (not staging):

..  code-block:: bash

    git clean -f

Unstage (undo adds):

..  code-block:: bash

    git reset HEAD index.html


Commit to most recent commit:

..  code-block:: bash

    git commit --amend -m "Message"

Update most recent commit message:

..  code-block:: bash

    git commit --amend -m "New Message"


Branch
******

Show branches:

..  code-block:: bash

    git branch

Create branch:

..  code-block:: bash

    git branch branchname

Change to branch:

..  code-block:: bash

    git checkout branchname

Create and change to new branch:

..  code-block:: bash

    git checkout -b branchname

Rename branch:

..  code-block:: bash

    git branch -m branchname new_branchname` or
    git branch --move branchname new_branchname

Show all completely merged branches with current branch:

..  code-block:: bash

    git branch --merged

Delete merged branch (only possible if not HEAD):

..  code-block:: bash

    git branch -d branchname` or
    git branch --delete branchname

Delete not merged branch:

..  code-block:: bash

    git branch -D branch_to_delete


Merge
*****

True merge (fast forward):

..  code-block:: bash

    git merge branchname

Merge to master (only if fast forward):

..  code-block:: bash

    git merge --ff-only branchname

Merge to master (forc a new commit):

..  code-block:: bash

    git merge --no-ff branchname

Stop merge (in case of conflicts):

..  code-block:: bash

    git merge --abort

Stop merge (in case of conflicts):

..  code-block:: bash

    git reset --merge // prior to v1.7.4


Stash
*****

Put in stash:

..  code-block:: bash

    git stash save "Message"

Show stash:

..  code-block:: bash

    git stash list

Show stash stats:

..  code-block:: bash

    git stash show stash@{0}

Show stash changes:

..  code-block:: bash

    git stash show -p stash@{0}

Use custom stash item and drop it:

..  code-block:: bash

    git stash pop stash@{0}

Use custom stash item and do not drop it:

..  code-block:: bash

    git stash apply stash@{0}

Delete custom stash item:

..  code-block:: bash

    git stash drop stash@{0}

Delete complete stash:

..  code-block:: bash

    git stash clear


Gitignore & Gitkeep
*******************

About: https://help.github.com/articles/ignoring-files

Useful templates: https://github.com/github/gitignore

Add or edit gitignore:

..  code-block:: bash

    vim .gitignore

Track empty dir:

..  code-block:: bash

    touch dir/.gitkeep


Log
***

Show commits:

..  code-block:: bash

    git log

Show oneline-summary of commits:

..  code-block:: bash

    git log --oneline

Show oneline-summary of commits with full SHA-1:

..  code-block:: bash

    git log --format=oneline

Show oneline-summary of the last three commits:

..  code-block:: bash

    git log --oneline -3

Show only custom commits:

..  code-block:: bash

    git log --author="Sven"
    git log --grep="Message"
    git log --until=2013-01-01
    git log --since=2013-01-01

Show only custom data of commit:

..  code-block:: bash

    git log --format=short
    git log --format=full
    git log --format=fuller
    git log --format=email
    git log --format=raw

Show changes:

..  code-block:: bash

    git log -p

Show every commit since special commit for custom file only:

..  code-block:: bash

    git log 6eb715d.. index.html

Show changes of every commit since special commit for custom file only:

..  code-block:: bash

    git log -p 6eb715d.. index.html

Show stats and summary of commits:

..  code-block:: bash

    git log --stat --summary

Show history of commits as graph:

..  code-block:: bash

    git log --graph

Show history of commits as graph-summary:

..  code-block:: bash

    git log --oneline --graph --all --decorate


Compare
*******

Compare modified files:

..  code-block:: bash

    git diff

Compare modified files and highlight changes only:

..  code-block:: bash

    git diff --color-words index.html

Compare modified files within the staging area:

..  code-block:: bash

    git diff --staged

Compare branches:

..  code-block:: bash

    git diff master..branchname

Compare branches like above:

..  code-block:: bash

    git diff --color-words master..branchname^

Compare commits:

..  code-block:: bash

    git diff 6eb715d
    git diff 6eb715d..HEAD
    git diff 6eb715d..537a09f

Compare commits of file:

..  code-block:: bash

    git diff 6eb715d index.html
    git diff 6eb715d..537a09f index.html

Compare without caring about spaces:

..  code-block:: bash

    git diff -b 6eb715d..HEAD or:
    git diff --ignore-space-change 6eb715d..HEAD

Compare without caring about all spaces:

..  code-block:: bash

    git diff -w 6eb715d..HEAD or:
    git diff --ignore-all-space 6eb715d..HEAD

Useful comparings:

..  code-block:: bash

    git diff --stat --summary 6eb715d..HEAD

Blame:

..  code-block:: bash

    git blame -L10,+1 index.html


Releases & Version Tags
***********************

Show all released versions:

..  code-block:: bash

    git tag

Show all released versions with comments:

..  code-block:: bash

    git tag -l -n1

Create release version:

..  code-block:: bash

    git tag v1.0.0

Create release version with comment:

..  code-block:: bash

    git tag -a v1.0.0 -m 'Message'

Checkout a specific release version:

..  code-block:: bash

    git checkout v1.0.0


Collaborate
***********

Show remote:

..  code-block:: bash

    git remote

Show remote details:

..  code-block:: bash

    git remote -v

Add remote origin from GitHub project:

..  code-block:: bash

    git remote add origin https://github.com/user/project.git

Add remote origin from existing empty project on server:

..  code-block:: bash

    git remote add origin ssh://root@123.123.123.123/path/to/repository/.git

Remove origin:

..  code-block:: bash

    git remote rm origin

Show remote branches:

..  code-block:: bash

    git branch -r

Show all branches:

..  code-block:: bash

    git branch -a

Compare:

..  code-block:: bash

    git diff origin/master..master

Push (set default with `-u`):

..  code-block:: bash

    git push -u origin master

Push to default:

..  code-block:: bash

    git push origin master

Fetch:

..  code-block:: bash

    git fetch origin

Pull:

..  code-block:: bash

    git pull

Pull specific branch:

..  code-block:: bash

    git pull origin branchname

Merge fetched commits:

..  code-block:: bash

    git merge origin/master

Clone to localhost:

..  code-block:: bash

    git clone https://github.com/user/project.git or:
    git clone ssh://user@domain.com/~/dir/.git

Clone to localhost folder:

..  code-block:: bash

    git clone https://github.com/user/project.git ~/dir/folder

Clone specific branch to localhost:

..  code-block:: bash

    git clone -b branchname https://github.com/user/project.git

Delete remote branch (push nothing):

..  code-block:: bash

    git push origin :branchname` or
    git push origin --delete branchname


Archive
*******

Create a zip-archive:

..  code-block:: bash

    git archive --format zip --output filename.zip master


Troubleshooting
***************

Ignore files that have already been committed to a Git repository: http://stackoverflow.com/a/1139797/1815847


Security
********

Hide Git on the web via `.htaccess`: `RedirectMatch 404 /\.git` 
(more info here: http://stackoverflow.com/a/17916515/1815847)


Large File Storage
******************

Website: https://git-lfs.github.com/

Install: `brew install git-lfs`

Track `*.psd` files: `git lfs track "*.psd"` (init, add, commit and push as written above)


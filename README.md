#Git Ignore

A small git extension to make it more convenient to work with the .gitignore file.

## Installation

Clone this repo and run

```
make
sudo make install
```

## Usage

###View a list of current ignore rules

```
git ignore list
```

Example output:

```
> git ignore list
# Rules in ignore file:
#   (use "git ignore add <rule>..." to add more)
#
#	git-ignore
#	*.o
#	*.dSYM
#
```
### Add a new rule

```
git ignore add <rule>...
```
Adds a new rule to the ignore list.

**Please not** that using wildcards here (like *) will be handled by your shell and added as individual items. If this is not the desired behaviour, then pass your rule as a string. Eg:

```
> git ignore add *.c
added ignore rule: git-ignore.c
added ignore rule: ignore-file.c
> git ignore add "*.c"
added ignore rule: *.c

```

## Future features

* Clear ignore list
* Pull and append ignore rules from [github](https://github.com/github/gitignore)


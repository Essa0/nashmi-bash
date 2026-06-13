*This project has been created as part of the 42 curriculum by iabiesat, zshkukan*

## Description:
Minishell project is implementation of unix-shell written in C as a part of 42 curriculum, the core objective is to discover and learn low-level process manage, file descriptor handle, and handle signal like ```ctrl + c```

## Instructions:

**The project divide to three part**:
- Lexer: Tokenize the input string into distinct units
- Parser: convert tokens into linked list of cmd structure
- Execution: manage all process creation pipe, redirection, and env variable

We take memory leaks seriously. Minishell has been rigorously tested using Valgrind and the Leaks utility. Every structure, from the Lexer’s tokens to the Executor’s environment copies, is meticulously freed upon exit or interruption (even via Ctrl+C)
#### requirement to run the project:
- GCC or CC compiler
- readline library
 ``` sudo apt install libreadline-dev ```

compilation
```bash
git clone "repo"
cd minishell
make
```
in this we create exec file ./minishell
**example to use**:
```bash
minishell > echo hello
minishell > echo "My home is $HOME and my status is $?"
minishell > echo -n -n -nnnn "No newline here"
```

### Feature
* Interactive prompt with command history
* Env variable expansion ($?)
* pipe with cleaning
* redirection
    - input ``` < ```
    - output ``` > ```
    - append ``` >> ```
    - heredoc ``` << ```
* signal handling: ```ctrl+c``` ```ctrl+D``` ```ctrl+\```
* builtin function:
    - echo
    - pwd
    - exit
    - export
    - cd
    - unset
    - env
    - exit

## Resources
https://www.gnu.org/software/bash/manual/bash.html

https://www.geeksforgeeks.org/nlp/what-is-tokenization/

https://mywiki.wooledge.org/BashParser

https://www.linux.org/threads/bash-03-%E2%80%93-command-line-processing.38676/

https://brennan.io/2015/01/16/write-a-shell-in-c/



## About using AI:
use AI tool help with find problem with code and suggest solutions, understanding edge cases in parsing and execution, planning and understanding the general architecture, help to understand some of bash behavior, understanding the debuging memory leaks detected by valgrind
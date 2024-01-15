# Shell Scripting Notes


# === RUNNING SHELL SCRIPTS ===
# we can make shell script files which automatically run when executed!

# step 1: create the shell script .sh file, let's call it myscript.sh
# step 2: in a terminal, navigate to the directory where the script is
# step 3: run the command: chmod +x myscript.sh, this makes the script executable by giving it permission
    # lets break down chmod +x myscript.sh,
    # "chmod": changemode, for modifying the file's permissions
    # "+x": adds execute permission to file, allows myscript.sh to be run as a program or script
    # other permissions: -r (read permission), -w (write permission)
# step 4: now execute myscript.sh in terminal as you would any executable by entering: ./myscript.sh
# done!!

# we prefix exetucables by ./myscript.sh to tell shell to find the myscript.sh in the current directory
# for executables added to the system's PATH environment, we do not need ./ as those executables/programs are "global"
# an example is how we type in gcc without ./


# === SSH ===
# to ssh into a remote location use the following command:
# ssh <username>@<remote_host>
# for example, <utorid>@dhXXXXpcXX.utm.utoronto.ca
# type exit to exit the ssh


# === ASIDE ===
# other useful command line / terminal / bash / powershell things that may be specific to windows

# FIND ANY PROCESSES RUNNING FROM SPECIFIC DIRECTORY (windows):
# run powershell as admin, and enter: Get-Process | Where-Object { $_.Path -like "C:\path\to\dir*" }
# replace C with the proper drive, D, E, F, etc.
# power shell will print all processes running from the specificed directory, eg;
# Handles  NPM(K)    PM(K)      WS(K)     CPU(s)     Id  SI ProcessName
# -------  ------    -----      -----     ------     --  -- -----------
#     151       8     1680       5232       0.05  21128   0 XSpltVidSvc

# JUNCTION LINKS (windows):
# open cmd as admin and navigate to the directory where you want to create the links
# enter: mklink /J "link-name" "path\to\actual\stuff"
# this will create a symbolic junction link "link-name" in the present working directory which points to "path\to\actual\stuff".
# note that you can only point to directories, not other files.
# junction links are very useful for keeping synced folders, allowing access to the same content in two different places
# whereas shortcuts are merely a link that jumps you to the source.


# === COMMANDS ===
# cd <path>: change directory to path, can use .. in place of <path> to jump into current directory's parent directory
# ls: list present files in current directory
# gcc -o main main.c: 

# DECLARING VARIABLES
x="Hello World!"
# no space around =

# ARITHMETIC
x=1
y=1
z=$((x + y)) # must encapsulate math with $(( ))
echo $z # prints 2

# Linux Commands Practice

## 1. `ls`
- **Usage**: Lists directory contents.
- **Example**:
  ```bash
  ls
  ```
- **Output**:
  ```
  Desktop    Downloads  Pictures  Templates  hello  snap
  Documents  Music      Public    Videos     hi
  ```

## 2. `cd`
- **Usage**: Changes the directory.
- **Example**:
  ```bash
  pwd
  cd Documents
  pwd
  ```
- **Output**:
  ```
  /home/parallels
  /home/parallels/Documents
  ```

## 3. `pwd`
- **Usage**: Prints the current working directory.
- **Example**:
  ```bash
  pwd
  ```
- **Output**:
  ```
  /home/parallels
  ```

## 4. `mkdir`
- **Usage**: Creates a new directory.
- **Example**: 
  ```bash
  ls
  mkdir hi
  ls
  ```
- **Output**:
  ```
  Desktop  Documents  Downloads  Music  Pictures  Public  Templates  Videos  snap
  
  Desktop  Documents  Downloads  Music  Pictures  Public  Templates  Videos  hi  snap
  ```

## 5. `rm`
- **Usage**: Removes files or directories.
- **Example**:
  ```bash
  ls
  rm hi
  ls
  ```
- **Output**:
  ```
  Desktop  Documents  Downloads  Music  Pictures  Public  Templates  Videos  hi  snap

  Desktop  Documents  Downloads  Music  Pictures  Public  Templates  Videos  snap
  ```

## 6. `cp`
- **Usage**: Copies files or directories.
- **Example**:
  ```bash
  touch hello.txt
  ls
  cp hello.txt ~/hi
  ls
  cd hi
  ls
  ```
- **Output**:
  ```
  Desktop    Downloads  Pictures  Templates  hello.txt  snap
  Documents  Music      Public    Videos     hi
  
  Desktop    Downloads  Pictures  Templates  hello.txt  snap
  Documents  Music      Public    Videos     hi

  hello.txt
  ```

## 7. `mv`
- **Usage**: Moves or renames files or directories.
- **Example**:
  ```bash
  ls 
  mv hello.txt ~/hi
  ls
  cd hi
  ls
  ```
- **Output**:
  ```
  Desktop    Downloads  Pictures  Templates  hello.txt  snap
  Documents  Music      Public    Videos     hi

  Desktop  Documents  Downloads  Music  Pictures  Public  Templates  Videos  hi  snap

  hello.txt
  ```

## 8. `cat`
- **Usage**: Concatenates and displays file content.
- **Example**:
  ```bash
  cat hello.txt
  ```
- **Output**:
  ```
  welcome to task 7
  ```

## 9. `nano`
- **Usage**: Edits text files in the terminal.
- **Example**:
  ```bash
  nano hello.txt

  welcome to task 7

  cat hello.txt
  ```
- **Output**:
  ```
  (nano editor opens for editing file.txt)
  welcome to task 7
  ```

# nm/objdump - ELF exploration

nm/objdump is an {Epitech} 2nd year project. It's part of *Unix System Programming* module.

> **⚠️ If you're an Epitech student, be aware that copying any part of this code is considered cheating and would cause an -42!**

## Purpose

The purpose of this project is to implement equivalents of the system commands `nm` (without any options) and `objdump` (which always behaves as if the `-f` and `-s` options are applied). Both programs must support handling multiple parameters. The programs must work with the following file formats:
- Relocatable files (`.o` and `.a`)
- Shared files (`.so`)
- Executable files

For more information about the [`nm`](https://man7.org/linux/man-pages/man1/nm.1.html) and [`objdump`](https://man7.org/linux/man-pages/man1/objdump.1.html) system commands, please consult their associated manual pages.

## Constraints

The following functions are forbidden to ensure the `nm` and `objdump` system commands aren't called:
- `exec*` (`execl`, `execv`, etc.)
- `system`
- Any other function capable of executing `nm` or `objdump`

## Tests results

<table>
  <thead>
    <tr>
      <th>Name</th>
      <th>Percentage</th>
      <th>Tests</th>
      <th>Crash?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>preliminary</td>
      <td>100%</td>
      <td>2/2</td>
      <td>No</td>
    </tr>
    <tr>
      <td>nm basics</td>
      <td>100%</td>
      <td>5/5</td>
      <td>No</td>
    </tr>
    <tr>
      <td>objdump basics</td>
      <td>75%</td>
      <td>3/4</td>
      <td>No</td>
    </tr>
    <tr>
      <td>nm args tests</td>
      <td>100%</td>
      <td>2/2</td>
      <td>No</td>
    </tr>
    <tr>
      <td>nm standard tests</td>
      <td>100%</td>
      <td>5/5</td>
      <td>No</td>
    </tr>
    <tr>
      <td>nm error tests</td>
      <td>50%</td>
      <td>1/2</td>
      <td>No</td>
    </tr>
    <tr>
      <td>nm advanced tests</td>
      <td>0%</td>
      <td>0/2</td>
      <td>No</td>
    </tr>
    <tr>
      <td>nm flag & address tests</td>
      <td>100%</td>
      <td>5/5</td>
      <td>No</td>
    </tr>
    <tr>
      <td>nm full compliance tests</td>
      <td>100%</td>
      <td>4/4</td>
      <td>No</td>
    </tr>
    <tr>
      <td>objdump header tests</td>
      <td>71.4%</td>
      <td>10/14</td>
      <td>No</td>
    </tr>
    <tr>
      <td>objdump cheater test</td>
      <td>0%</td>
      <td>0/1</td>
      <td>No</td>
    </tr>
    <tr>
      <td>objdump section name tests</td>
      <td>100%</td>
      <td>2/2</td>
      <td>No</td>
    </tr>
    <tr>
      <td>objdump args tests</td>
      <td>50%</td>
      <td>1/2</td>
      <td>No</td>
    </tr>
    <tr>
      <td>objdump section data tests</td>
      <td>66.7%</td>
      <td>2/3</td>
      <td>No</td>
    </tr>
    <tr>
      <td>objdump error tests</td>
      <td>50%</td>
      <td>1/2</td>
      <td>No</td>
    </tr>
    <tr>
      <td>objdump advanced tests</td>
      <td>0%</td>
      <td>0/2</td>
      <td>No</td>
    </tr>
    <tr>
      <td>objdump full compliance tests</td>
      <td>50%</td>
      <td>2/4</td>
      <td>No</td>
    </tr>
  </tbody>
  <tfoot>
    <tr>
      <th>Total</th>
      <th>73.8%</th>
      <th>45/61</th>
      <th>No</th>
    </tr>
  </tfoot>
</table>

## How to use

### Requirements

To use this program, you need to install some tools:
- [GCC](https://gcc.gnu.org/)
- [GNU Make](https://www.gnu.org/software/make/)

### Usage

To compile the executables, run:
```sh
make
```

To compile only `my_nm` executable, run:
```sh
make nm
```

To compile only `my_objdump` executable, run:
```sh
make objdump
```

To clean object files, run:
```sh
make clean
```

To clean both object files and executable files, run:
```sh
make fclean
```

To execute the programs, run:
```sh
./my_nm <file_1> [<file_2> [...]]
```
```sh
./my_objdump <file_1> [<file_2> [...]]
```
When running one of the program, replace the placeholders (`<file_1>`, etc.) with the actual names of one or more [supported files](#purpose).

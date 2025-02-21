# mygrep_project
Program for searching strings in text files

## Programm functionality
Bellow is a short list of functions.
As well as description to each function.
You can also see examples of usage after every description.

| Function                   | Short decription                                                                                                                                                                                  | Date implemented |
|----------------------------|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|------------------|
| Simple search              | Searching for **first** instance of provided string in another provided string                                                                                                                        | 17.02.2025       |
| Advanced search            | Searching provided .txt file on **every** occurrence of provided string                                                                                                                               | 19.02.2025         |
| Options                    | Program takes argument **-0** that is sign that this is the start of the **options** string                                                                                                      | 19.02.2025         |
| Lines displaying           | **l** - one of available arguments for options string if provided, program will display  lines where matching strings by advanced searching  were found                                          | 19.02.2025         |
| Occurrence                  | **o** - one of available arguments for options string if provided, program will display  amount lines where matching strings by advanced searching  were found, on the last string of a programm | 19.02.2025          |
| Reverced search            | **r** - one of available arguments for options string if provided, program will search line, that DON'T contain provided string                                                                  | 19.02.2025         |
| Not case cencetive search | **i** - one of available arguments for options string if provided, program will search lines no matter  the case of the letters                                                                  | 19.02.2025        |

### Simple search 
When a program has been started in a console **without any arguments** it will perfom a simple search. Program will ask user to enter
a string where it should search from, after that program will ask to enter a string that we have to search. Program will display **only the first** occurrence of
provided string. 

<img width="531" alt="mg1" src="https://github.com/user-attachments/assets/4de5b01a-62d4-4bd2-b7c5-428bccfbc150" />

### Advanced search 
When a program has been started in a console with two arguments after a name of a program. **First** argument to the right is a string that we
want to search and the **second** argument to the right is a name of a .txt file where the search should be performed. Program will display **every occurrence** of a string
in a .txt file

<img width="762" alt="mg2" src="https://github.com/user-attachments/assets/a1fa4bbf-dabf-4345-8b2e-97a8286277be" />

NOTE: If the .txt file and a program aren't placed in a same folder, you'll need to provide full path to the .txt file
in order to open it

#### Advanced search settings
The program has some settings functions that can be provided in a special string. 
If you want to set settings to a program you can write it as a first argument to the right of a program name,
after that you'll need to write string that you are searching for, and after that you'll need to write a .txt file name.
When you're writing settings your string should start with ```-o``` argument (short for options) and can be followed by any of the
following arguments in any sequence.

##### Lines displaying
```l``` - when you provide this argument, program will **display the number**  of the line to the left of every mathing string.
<img width="799" alt="mg3" src="https://github.com/user-attachments/assets/82f552df-d3c8-498b-8302-a010857a5e14" />


##### Occurrence
```o``` - when you provide this argument, program will display **total amount of mathing strings**, after it displays all mathing strings.
<img width="795" alt="mg4" src="https://github.com/user-attachments/assets/8532c523-ef4f-48d3-8184-2367c459090d" />

##### Reverced search
```r```- when you provide this argument, program will search lines, that **DON'T** contain provided string.         
<img width="811" alt="mg5" src="https://github.com/user-attachments/assets/4ec30250-4aaa-4672-8dcd-ef6e84810820" />

Note, that this example above prints almost all 200+ lines of example file, screenshoot showing only some of them 

##### Not case cencetive search
```i``` - when you provide this argument, program will search lines no matter  the case of the letters.
<img width="802" alt="mg6" src="https://github.com/user-attachments/assets/92c33d07-89e9-4a6c-93de-0aefc541f691" />

### Example
Example of usage of settings together
<img width="845" alt="mg7 1" src="https://github.com/user-attachments/assets/be13db18-586b-40a9-abfa-14f0284e633e" />
<img width="788" alt="mg7 2" src="https://github.com/user-attachments/assets/d416c1d3-6445-45e8-a124-cf41cde1648d" />

### Error handling
The program can produce following errors:

<img width="745" alt="E1" src="https://github.com/user-attachments/assets/48225460-cf2c-4a64-86fa-22538d9a183e" />


<img width="798" alt="E2" src="https://github.com/user-attachments/assets/7cda18ac-872f-4d2c-b142-e452c094cc56" />
Because "Following" considered as a setting string in this example, because we have 3 arguments after file name


<img width="812" alt="E3" src="https://github.com/user-attachments/assets/3ceebfbe-d471-403d-adb8-74335273c3c6" />
Because you cannot same same paramether twice in a settings string


<img width="809" alt="E4" src="https://github.com/user-attachments/assets/e8ce009a-24d9-4c8f-ba2d-3673c6f863f7" />
Because there is no such a paramether for a settings string

### How to compile
You'll need to open this project in a Visual Studio and then build it using **ctrl + shift + b** or by starting and
closing a program in a debug mode. After this you'll have your .exe file in a project_folder/x64/debug/ folder. This is
where you can run it in a cmd. 

Send me an email on dlvelel777@gmail.com if you have problems compiling it

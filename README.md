# Calendar Project

![image](https://github.com/user-attachments/assets/03c9ed9e-e796-4db2-8f4b-806da9e3371c)


This is a calendar application developed as part of the "Fundamentals of Programming" course. The project is designed to help users manage their schedules, add notes, set reminders, and flag important dates. The application is built using C++ and the SFML (Simple and Fast Multimedia Library) for graphical rendering.

## Features

- **Display Calendar**: The application displays a full-year calendar with the current date highlighted.
- **Add Notes**: Users can add notes to specific dates.
- **Repetitive Notes**: Users can add repetitive notes for specific days of the week.
- **Delete Notes**: Users can delete notes from specific dates.
- **Flag Dates**: Users can flag important dates with a distinct color.
- **Unflag Dates**: Users can remove the flag from a date.
- **Show Notes**: Users can view notes for a specific date.
- **Show All Notes**: Users can view all notes in the calendar.
- **Save Data**: All notes and flagged dates are saved to a file and loaded upon the next execution.
- **Add Reminder**: Users can set reminders for specific dates and times (reminder functionality is partially implemented).

## How to Use

1. **Run the Program**: Compile and run the program. A window will open displaying the calendar for the current year.
2. **Commands**: Use the following commands in the console to interact with the calendar:
   - `Add Note`: Add a note to a specific date.
   - `Add Repetitive Note`: Add a repetitive note for a specific day of the week.
   - `Delete Note`: Delete a note from a specific date.
   - `Flag`: Flag a specific date with a distinct color.
   - `Unflag`: Remove the flag from a specific date.
   - `Show`: Show the note for a specific date.
   - `Show All`: Show all notes in the calendar.
   - `Save`: Save all notes and flagged dates to a file.
   - `Add Reminder`: Set a reminder for a specific date and time (partially implemented).
   - `Exit`: Exit the program.

## Dependencies

- **SFML**: The project uses the SFML library for graphical rendering. Make sure to have SFML installed and properly configured in your development environment.
- **C++ Compiler**: The project is written in C++ and requires a compatible compiler (e.g., GCC, Clang, MSVC).

## Installation

1. Clone the repository:
 ```bash
   git clone https://github.com/your-username/calendar-project.git
 ```
2. Navigate to the project directory:
```bash
   cd calendar-project
```
3. Compile the project using your preferred C++ compiler. For example, using GCC:
```bash
   g++ -o calendar main.cpp -lsfml-graphics -lsfml-window -lsfml-system
```
4. Run the compiled executable:
```bash
  ./calendar
```

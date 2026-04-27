#!/bin/bash

FILE="students.txt"

# Create file if it does not exist
touch "$FILE"

add_student() {
echo "Enter Student Roll Number: "
read roll

# Check if roll number already exists
if grep -q "^$roll|" "$FILE"; then
echo "Student with Roll Number $roll already exists."
return
fi

echo "Enter Student Name: "
read name

echo "$roll|$name" >> "$FILE"
echo "Student record added successfully."
}
view_students() {
if [ ! -s "$FILE" ]; then
echo "No student records found."
return
fi
echo "--------------------------------"
    echo "Roll Number | Student Name"
    echo "--------------------------------"
    while IFS='|' read -r roll name
    do
        echo "$roll | $name"
    done < "$FILE"
    echo "--------------------------------"
}

update_student() {
    echo "Enter Roll Number to update: "
    read roll

    if ! grep -q "^$roll|" "$FILE"; then
        echo "Student record not found."
        return
    fi

    echo "Enter New Student Name: "
    read new_name

    awk -F'|' -v r="$roll" -v n="$new_name" 'BEGIN {OFS="|"} {
        if ($1 == r) $2 = n
        print
    }' "$FILE" > temp.txt && mv temp.txt "$FILE"

    echo "Student record updated successfully."
}

delete_student() {
    echo "Enter Roll Number to delete: "
    read roll

    if ! grep -q "^$roll|" "$FILE"; then
        echo "Student record not found."
        return
    fi

    awk -F'|' -v r="$roll" '$1 != r' "$FILE" > temp.txt && mv temp.txt "$FILE"

    echo "Student record deleted successfully."
}

while true
do
    echo ""
    echo "===== Student Record Management ====="
    echo "1. Add Student Record"
    echo "2. View Student Records"
    echo "3. Update Student Record"
    echo "4. Delete Student Record"
    echo "5. Exit"
    echo "Enter your choice: "
    read choice

    case $choice in
        1) add_student ;;
        2) view_students ;;
        3) update_student ;;
        4) delete_student ;;
        5) echo "Exiting..."; exit 0 ;;
        *) echo "Invalid choice. Please try again." ;;
    esac
done

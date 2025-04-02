/*
find surface_area = 2*l*w + 2*w*h + 2*h*l
find area of smallest_side using min of (lw,wh,hl)
the values in input.txt are in feet
find sq feet of paper total

---
ribbon - find length to order
*/

#include <stdio.h>

int main(void) {
    int length, width, height, smallest_side = 0, surface_area = 0, ribbon_wrap = 0, ribbon_bow = 0;
    int temp_1, temp_2, temp_3;
    FILE *fptr;
    fptr = fopen("input.txt", "r"); // read file

    if (fptr == NULL) { printf("Error file read"); return 1; }

    while (fscanf(fptr, "%dx%dx%d", &length, &width, &height) == 3) { // 3 to ensure 3 values are read
        temp_1 = length * width;
        temp_2 = width * height;
        temp_3 = height * length;

        int side1 = 2 * (length + width);
        int side2 = 2 * (width + height);
        int side3 = 2 * (height + length);

        surface_area += 2 * (temp_1 + temp_2 + temp_3);

        if (temp_1 <= temp_2 && temp_1 <= temp_3) {
            smallest_side += temp_1;
        } else if (temp_2 <= temp_1 && temp_2 <= temp_3) {
            smallest_side += temp_2;
        } else { smallest_side += temp_3; }

        int min_perimeter;
        if (side1 <= side2 && side1 <= side3) {
            min_perimeter = side1;
        } else if (side2 <= side1 && side2 <= side3) {
            min_perimeter = side2;
        } else {
            min_perimeter = side3;
        }

        ribbon_wrap += min_perimeter;
        ribbon_bow += length * width * height;
    }

    fclose(fptr);

    printf("Total square feet to be ordered is: %d\n", smallest_side + surface_area);
    printf("Total ribbon needed: %d\n", ribbon_wrap + ribbon_bow);

    return 0;
}
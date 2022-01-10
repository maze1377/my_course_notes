#include <stdio.h>
#include <string.h>

#define PI 3.14
#define MAX_LENGTH 100

struct Rectangle {
    int width;
    int height;
};

struct Circle {
    int radius;
};

struct Trapezius {
    int a;
    int b;
    int c;
    int d;
    int height;
};

struct Triangle {
    int a;
    int b;
    int c;
    int height;
};

int isEqual(char first[], char second[]) {
    return strcmp(first, second) == 0;
}

int getRectangleArea(struct Rectangle rectangle) {
    return rectangle.width * rectangle.height;
}

int getRectanglePerimeter(struct Rectangle rectangle) {
    return 2 * (rectangle.height + rectangle.width);
}

float getCircleArea(struct Circle circle) {
    return PI * circle.radius * circle.radius;
}

float getCirclePerimeter(struct Circle circle) {
    return PI * circle.radius * 2;
}

int getTrapeziusPerimeter(struct Trapezius trapezius) {
    return trapezius.a + trapezius.b + trapezius.c + trapezius.d;
}

float getTrapeziusArea(struct Trapezius trapezius) {
    return (float) ((trapezius.a + trapezius.b) * trapezius.height) / 2;
}

int getTrianglePerimeter(struct Triangle triangle) {
    return triangle.a + triangle.b + triangle.c;
}

float getTriangleArea(struct Triangle triangle) {
    return (float) (triangle.a * triangle.height) / 2;
}

void printOutput(char shape[]) {
    if(isEqual(shape, "Rectangle")) {
        struct Rectangle rectangle;
        scanf("%d", &rectangle.width);
        scanf("%d", &rectangle.height);

        printf("%.3f", (float) getRectanglePerimeter(rectangle));
        printf("-");
        printf("%.3f", (float)  getRectangleArea(rectangle));
    } else if(isEqual(shape, "Circle")) {
        struct Circle circle;
        scanf("%d", &circle.radius);

        printf("%.3f", getCirclePerimeter(circle));
        printf("-");
        printf("%.3f", getCircleArea(circle));
    } else if(isEqual(shape, "Trapezius")) {
        struct Trapezius trapezius;
        scanf("%d", &trapezius.a);
        scanf("%d", &trapezius.b);
        scanf("%d", &trapezius.c);
        scanf("%d", &trapezius.d);
        scanf("%d", &trapezius.height);


        printf("%.3f", (float) getTrapeziusPerimeter(trapezius));
        printf("-");
        printf("%.3f", (float) getTrapeziusArea(trapezius));
    } else {
        struct Triangle triangle;
        scanf("%d", &triangle.a);
        scanf("%d", &triangle.b);
        scanf("%d", &triangle.c);
        scanf("%d", &triangle.height);

        printf("%.3f", (float) getTrianglePerimeter(triangle));
        printf("-");
        printf("%.3f", (float) getTriangleArea(triangle));
    }
    printf("\n");
}

int main() {
    int shapeCount;
    scanf("%d", &shapeCount);

    for(int i = 0; i < shapeCount; i++) {
        char shape[MAX_LENGTH];
        scanf("%s", shape);
        printOutput(shape);
    }

}
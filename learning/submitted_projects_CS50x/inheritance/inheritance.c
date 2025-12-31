#define _DEFAULT_SOURCE
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct person
{
    struct person *parents[2];
    char alleles[2];
} person;

const int GENERATIONS = 3;
const int INDENT_LENGTH = 4;

person *create_family(int generations);
void print_family(person *p, int generation);
void free_family(person *p);
char random_allele();
char allele_parent(person *p);

int main(void)
{
    srandom(time(0));

    person *p = create_family(GENERATIONS);

    print_family(p, 0);

    free_family(p);
}

person *create_family(int generations)
{
    person *child = malloc(sizeof(person));
    if (!child)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    if (generations > 1)
    {
        // Recursively create parents
        child->parents[0] = create_family(generations - 1);
        child->parents[1] = create_family(generations - 1);

        // Inherit one allele from each parent
        child->alleles[0] = allele_parent(child->parents[0]);
        child->alleles[1] = allele_parent(child->parents[1]);
    }
    else
    {
        // No parents at last generation
        child->parents[0] = NULL;
        child->parents[1] = NULL;

        // Random alleles for base generation
        child->alleles[0] = random_allele();
        child->alleles[1] = random_allele();
    }

    return child;
}

void free_family(person *p)
{
    if (p == NULL)
        return;

    // Free parents first
    free_family(p->parents[0]);
    free_family(p->parents[1]);

    // Free this person
    free(p);
}

void print_family(person *p, int generation)
{
    if (p == NULL)
        return;

    for (int i = 0; i < generation * INDENT_LENGTH; i++)
        printf(" ");

    if (generation == 0)
        printf("Child (Generation %i): blood type %c%c\n", generation, p->alleles[0],
               p->alleles[1]);
    else if (generation == 1)
        printf("Parent (Generation %i): blood type %c%c\n", generation, p->alleles[0],
               p->alleles[1]);
    else
    {
        for (int i = 0; i < generation - 2; i++)
            printf("Great-");
        printf("Grandparent (Generation %i): blood type %c%c\n", generation, p->alleles[0],
               p->alleles[1]);
    }

    print_family(p->parents[0], generation + 1);
    print_family(p->parents[1], generation + 1);
}

char random_allele()
{
    int r = random() % 3;
    if (r == 0)
        return 'A';
    else if (r == 1)
        return 'B';
    else
        return 'O';
}

char allele_parent(person *p)
{
    int r = random() % 2;
    return p->alleles[r];
}

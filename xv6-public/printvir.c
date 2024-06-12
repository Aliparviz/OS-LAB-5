#include "types.h"
#include "stat.h"
#include "user.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"

struct proc *myproc(void);
int printvir(void);

int
main(int argc, char *argv[])
{
    int num_vir_pages = printvir();
    printf(1, "Number of virtual pages: %d\n", num_vir_pages);
    exit();
}

int printvir()
{
    // Get the current process
    struct proc *curproc = myproc();
    if (curproc == 0)
        return -1;

    // Get the process page table
    pde_t *pgdir = curproc->pgdir;

    int num_vir_pages = 0;

    // Iterate over the page table entries
    for (int i = 0; i < NPDENTRIES; i++)
    {
        pde_t pde = pgdir[i];
        if (pde & PTE_P)
        {
            num_vir_pages++;
        }
    }

    return num_vir_pages;
}
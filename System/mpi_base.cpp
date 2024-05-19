#include <stdio.h>
#include <mpi.h>

double x;

int main (int argc, char **argv) {
    MPI_Init(&argc, &argv);
    int rank, size;
        MPI_Comm_rank(MPI_COMM_WORLD, &rank);
        MPI_Comm_size(MPI_COMM_WORLD, &size);

        if (rank == 0) {
            x = 10.1;
        }
        double* p = &x; // 将指针p的类型更改为指向指针的指针

        // 使用 MPI_Bcast 函数将 0 号进程的 x 地址的地址广播给其他所有进程
        MPI_Bcast(&p, 1, MPI_LONG, 0, MPI_COMM_WORLD);

        MPI_Barrier(MPI_COMM_WORLD);
        printf("Process %d has value %f\n", rank, *p);

        MPI_Finalize();
    return 0;
}
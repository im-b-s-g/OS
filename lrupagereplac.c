/*#include<stdio.h>

int main()
{
 int m, n, position, k, l;
 int a = 0, b = 0, page_fault = 0;

 int total_frames = 3;
 int frames[total_frames];
 int temp[total_frames];
 int pages[] = {1, 2, 3, 2, 1, 5, 2, 1, 6, 2, 5, 6, 3, 1, 3, 6, 1, 2, 4, 3};
 int total_pages = sizeof(pages)/sizeof(pages[0]);
 for(m = 0; m < total_frames; m++){
 frames[m] = -1;
 }

 for(n = 0; n < total_pages; n++)
 {
 printf("%d: ", pages[n]);
 a = 0, b = 0;
 for(m = 0; m < total_frames; m++)
 {
 if(frames[m] == pages[n])
 {
 a = 1;
 b = 1;
 break;
 }
 }
 if(a == 0)
 {
 for(m = 0; m < total_frames; m++)
 {
 if(frames[m] == -1)
 {
 frames[m] = pages[n];
 b = 1;
 page_fault++;
 break;
 }
 }
 }
 if(b == 0)
 {
 for(m = 0; m < total_frames; m++)
 {
 temp[m] = 0;
 }
 for(k = n - 1, l = 1; l <= total_frames - 1; l++, k--)
 {
 for(m = 0; m < total_frames; m++)
 {
    if(frames[m] == pages[k])
 {
 temp[m] = 1;
 }
 }
 }
 for(m = 0; m < total_frames; m++)
 {
 if(temp[m] == 0)
 position = m;
 }
 frames[position] = pages[n];
 page_fault++;
 }

 for(m = 0; m < total_frames; m++)
 {
 printf("%d\t", frames[m]);
 }
 printf("\n");
 }
 printf("\nTotal Number of Page Faults:\t%d\n", page_fault);

 return 0;}

*/

// #include <stdio.h>
// int main()
// {
//     int m, n, position, k, l;
//     int a = 0, b = 0, page_fault = 0;
//     int total_frames = 3;
//     int frames[total_frames];
//     int temp[total_frames];
//     int pages[] = {1, 2, 3, 2, 1, 5, 2, 1, 6, 2, 5, 6, 3, 1, 3, 6, 1, 2, 4, 3};
//     int total_pages = sizeof(pages) / sizeof(pages[0]);

//     // Initialize frames with -1, indicating empty frames
//     for (m = 0; m < total_frames; m++)
//     {
//         frames[m] = -1;
//     }
//     // Iterate through each page in the sequence
//     for (n = 0; n < total_pages; n++)
//     {
//         printf("%d: ", pages[n]);
//         a = 0, b = 0;
//         // Check if the page is already in memory
//         for (m = 0; m < total_frames; m++)
//         {
//             if (frames[m] == pages[n])
//             {
//                 a = 1;
//                 b = 1;
//                 break;
//             }
//         }
//         // If the page is not in memory, check for an empty frame
//         if (a == 0)
//         {
//             for (m = 0; m < total_frames; m++)
//             {
//                 if (frames[m] == -1)
//                 {
//                     frames[m] = pages[n];
//                     b = 1;
//                     page_fault++;
//                     break;
//                 }
//             }
//         }
//         // If no empty frame is found, use LRU to replace a page
//         if (b == 0)
//         {
//             // Mark all frames as not used
//             for (m = 0; m < total_frames; m++)
//             {
//                 temp[m] = 0;
//             }
//             // Check the usage of frames for LRU replacement
//             for (k = n - 1, l = 1; l <= total_frames - 1; l++, k--)
//             {
//                 for (m = 0; m < total_frames; m++)
//                 {
//                     if (frames[m] == pages[k])
//                     {
//                         temp[m] = 1;
//                     }
//                 }
//             }
//             // Find the least recently used frame
//             for (m = 0; m < total_frames; m++)
//             {
//                 if (temp[m] == 0)
//                 {
//                     position = m;
//                 }
//             }
//             // Replace the page in the least recently used frame
//             frames[position] = pages[n];
//             page_fault++;
//         }
//         // Display the current state of frames after each page access
//         for (m = 0; m < total_frames; m++)
//         {
//             printf("%d\t", frames[m]);
//         }
//         printf("\n");
//     }
//     // Display the total number of page faults
//     printf("\nTotal Number of Page Faults:\t%d\n", page_fault);

//     return 0;
// }
///----------------------------------------------------------------------------------------------------------------

#include <stdio.h>
int main()
{
    int m, n, position, k, l;
    int a = 0, b = 0, page_fault = 0;
    int total_frames = 3;
    int frames[total_frames];
    int temp[total_frames];
    int pages[] = {1, 2, 3, 2, 1, 5, 2, 1, 6, 2, 5, 6, 3, 1, 3, 6, 1, 2, 4, 3};
    int total_pages = sizeof(pages) / sizeof(pages[0]);

    for (m = 0; m < total_frames; m++)
    {
        frames[m] = -1;
    }
    for (n = 0; n < total_pages; n++)
    {
        printf("%d: ", pages[n]);
        a = 0, b = 0;
        for (m = 0; m < total_frames; m++)
        {
            if (frames[m] == pages[n])
            {
                a = 1;
                b = 1;
                break;
            }
        }
        if (a == 0)
        {
            for (m = 0; m < total_frames; m++)
            {
                if (frames[m] == -1)
                {
                    frames[m] = pages[n];
                    b = 1;
                    page_fault++;
                    break;
                }
            }
        }
        if (b == 0)
        {
            for (m = 0; m < total_frames; m++)
            {
                temp[m] = 0;
            }
            for (k = n - 1, l = 1; l <= total_frames - 1; l++, k--)
            {
                for (m = 0; m < total_frames; m++)
                {
                    if (frames[m] == pages[k])
                    {
                        temp[m] = 1;
                    }
                }
            }
            for (m = 0; m < total_frames; m++)
            {
                if (temp[m] == 0)
                {
                    position = m;
                }
            }
            frames[position] = pages[n];
            page_fault++;
        }
        for (m = 0; m < total_frames; m++)
        {
            printf("%d\t", frames[m]);
        }
        printf("\n");
    }
    printf("\nTotal Number of Page Faults:\t%d\n", page_fault);
    return 0;
}
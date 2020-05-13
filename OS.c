#include<stdio.h>
#include<conio.h>

int findLRU(int time[], int n){
	int i, minimum = time[0], pos = 0;
 
	for(i = 1; i < n; ++i){
		if(time[i] < minimum){
			minimum = time[i];
			pos = i;
		}
	}
	
	return pos;
}
 
int LRU(int no_of_frames,int no_of_pages,int pages[])
{
    int  frames[10], counter = 0, time[10], flag1, flag2, i, j, pos, faults = 0;
	
    
	for(i = 0; i < no_of_frames; ++i){
    	frames[i] = -1;
    }
    
    for(i = 0; i < no_of_pages; ++i){
    	flag1 = flag2 = 0;
    	
    	for(j = 0; j < no_of_frames; ++j){
    		if(frames[j] == pages[i]){
	    		counter++;
	    		time[j] = counter;
	   			flag1 = flag2 = 1;
	   			break;
   			}
    	}
    	
    	if(flag1 == 0){
			for(j = 0; j < no_of_frames; ++j){
	    		if(frames[j] == -1){
	    			counter++;
	    			faults++;
	    			frames[j] = pages[i];
	    			time[j] = counter;
	    			flag2 = 1;
	    			break;
	    		}
    		}	
    	}
    	
    	if(flag2 == 0){
    		pos = findLRU(time, no_of_frames);
    		counter++;
    		faults++;
    		frames[pos] = pages[i];
    		time[pos] = counter;
    	}
    	
	}
	printf("\nTotal Page Faults in Least Recently Used  Page Replacement = %d", faults);
}

void OPR(int nf,int psz,int page[])
{
    int fr[5],i,j,k,t[5],p=1,flag=0,t1,u[5];
    for(i=1; i<=nf; i++)
        fr[i]=-1;
    for(i=1; i<=psz; i++)
    {
        if(full(fr,nf)==1)
           break;
        else
        {
            flag=0;
            for(j=1; j<=nf; j++)
            {
               if(page[i]==fr[j])
                {
                    flag=1;
                
                    break;
                }
            }
            if(flag==0)
            {
                fr[p]=page[i];
             
                p++;
            }

        }
    }
    p=0;
    for(; i<=psz; i++)
    {
        flag=0;
        for(j=1; j<=nf; j++)
        {
            if(page[i]==fr[j])
            {
                flag=1;
                break;
            }
        }
       if(flag==0)
        {
            p++;
            for(j=1; j<=nf; j++)
            {
                for(k=i+1; k<=psz; k++)
                {
                    if(fr[j]==page[k])
                    {
                        u[j]=k;
                        break;
                    }
                    else
                        u[j]=21;
                }
            }
            for(j=1; j<=nf; j++)
                t[j]=u[j];
            for(j=1; j<=nf; j++)
            {
                for(k=j+1; k<=nf; k++)
                {
                    if(t[j]<t[k])
                    {
                        t1=t[j];
                        t[j]=t[k];
                        t[k]=t1;
                    }
                }
            }
            for(j=1; j<=nf; j++)
            {
                if(t[1]==u[j])
                {
                    fr[j]=page[i];
                    u[j]=i;
                }
            }
        }
      
    }
    printf("\nTotal Page Faults in Optimal Page Replacement = %d",p+3);
// getch();
}
int full(int a[],int n)
{
    int k;
    for(k=1; k<=n; k++)
    {
        if(a[k]==-1)
            return 0;
    }
    return 1;
}
int main ()
{
    int no_of_frames, no_of_pages, pages[30],i;
    printf("Enter number of frames: ");
	scanf("%d", &no_of_frames);
	
	printf("Enter number of pages: ");
	scanf("%d", &no_of_pages);
	
	printf("Enter reference string: ");
	
    for(i = 0; i < no_of_pages; ++i){
    	scanf("%d", &pages[i]);
    }
    LRU(no_of_frames, no_of_pages,pages);
    OPR(no_of_frames, no_of_pages,pages);
}
    
    
    
    
    
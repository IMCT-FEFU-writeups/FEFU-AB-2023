#include <stdio.h>
#include <stdlib.h>
int bin_search(int* array, int left, int right, int key){
	if(left >= right){
		return array[left]==key?left:-1;
	}
	int middle = (left+right)/2;
	if(array[middle]==key){
		return middle;
	}
	if(array[middle]>key){
		return bin_search(array,left,middle,key);
	}
	return bin_search(array,middle+1,right,key);
}

int cmp_i(const void *a, const void *b){
	return *((int*)a) > *((int*)b)? 1:-1;
}

int add(int *set,int *size,int key){
	if(*size == 0){
		set[(*size)++]=key;
		return 1;
	}
	int start_key = key;
	for(int i = 0; i < *size; i++){
		if(key < set[i]){
			int tmp = set[i];
			set[i] = key;
			key = tmp;
		}
		else if(key == set[i]){
			break;
		}
		if(i == *size-1){
			if(key > set[i]){
				set[(*size)++]=key;
				return 1;
			}
		}
	}
	if(key == start_key){
		return 0;
	}
	(*size)++;
	return 1;
}

int bin_maxis_i(int *array,int array_size, int left, int right, int key){
	if(left >= right){
		if(array[left]==key){
			return left;
		}
		if(left==array_size-1 && array[left]<=key){
			return left;
		}
		if(left==0){
			return -1;
		}
		if(array[left] > key && array[left-1] < key){
			return left-1;
		}
		if(array[left] < key && array[left+1] > key){
			return left;
		}
		return -1;
	}
	int middle = (left+right)/2;
	if(array[middle]==key){
		return middle;
	}
	if(array[middle]>key){
		return bin_maxis_i(array,array_size,left,middle,key);
	}
	
	return bin_maxis_i(array,array_size,middle+1,right,key);
}

int bin_least_i(int* row,int rows_size, int left, int right, int key){
	if(left >= right){
		if(row[left]>=key){
			return left;
		}
		if(left == 0 && row[left]>=key){
			return 0;
		}
		if(left >= rows_size-1){
			return -1;
		}
		if(row[left] < key && row[left+1] > key){
			return left+1;
		}
		if(row[left-1] < key && row[left] > key){
			return left;
		}
		return -1;
	}
	int middle = (left+right)/2;
	if(row[middle]==key){
		return middle;
	}
	if(row[middle]>key){
		return bin_least_i(row,rows_size,left,middle,key);
	}
	
	return bin_least_i(row,rows_size,middle+1,right,key);
}

struct Coord{
	int x,y;
};

int cmp(const void *a, const void *b){
	if(((struct Coord *)a)->y > ((struct Coord *)b)->y){
		return 1;
	}
	if(((struct Coord *)a)->y < ((struct Coord *)b)->y){
		return -1;
	}
	if(((struct Coord *)a)->x > ((struct Coord *)b)->x){
		return 1;
	}
	return -1;
}

int main() {
	FILE *fIn, *fOut;
	fIn = fopen("input.txt","r");
	int N;
	long long S;
	fscanf(fIn,"%d %lld",&N,&S);
	int *rows = calloc(N,4);
	int *cols = calloc(N,4);
	int rows_size = 0;
	
	int cols_size = 0;
	
	struct Coord *buffer = calloc(N,sizeof(struct Coord));
	
	for(struct Coord *index = buffer; index < buffer+N; index++){
		fscanf(fIn,"%d %d",&index->x,&index->y);
		add(rows, &rows_size, index->y);
		add(cols, &cols_size, index->x);
	}
  
	fclose(fIn);
	qsort(buffer,N,sizeof(struct Coord),cmp);

	int *tree_prefix = calloc(rows_size*cols_size,4);
	
	int last_y = buffer[0].y;
	int tree_row = 0;
	for(struct Coord *index = buffer; index < buffer+N; index++){
		if(last_y<index->y){
			last_y=index->y;
			tree_row++;
		}
		tree_prefix[tree_row*cols_size+bin_search(cols,0,cols_size-1,index->x)] = 1;
	}
	free(buffer);
	
	
	for(int row = 0; row < rows_size; row++){
		for(int col = 1; col < cols_size; col++){
			tree_prefix[row*cols_size+col] += tree_prefix[row*cols_size+col-1];
		}
	}
	for(int row = 1; row < rows_size; row++){
		for(int col = 0; col < cols_size; col++){
			tree_prefix[row*cols_size+col] += tree_prefix[(row-1)*cols_size+col];
		}
	}
	
	fOut = fopen("output.txt","w");
	
	int max = 0, lx = 0, ly = 0, rx = 0, ry = 0;
	for(int start_row = 0; start_row < rows_size; start_row++){
		int possible_trees = N;
		if(start_row>0){
			possible_trees-=tree_prefix[(start_row-1)*cols_size+cols_size-1];
		}
		for(int start_col = 0; start_col < cols_size; start_col++){
			for(int last_col = start_col; last_col < cols_size; last_col++){
				int last_row = 0, tree_cnt = 0;
				
				if(last_col == start_col){
					last_row = rows_size-1;
				}
				else{
					last_row = bin_maxis_i(rows,rows_size,0,rows_size-1,S/(cols[last_col]-cols[start_col])+rows[start_row]);
					if(last_row == start_row){
						last_col = cols_size-1;
					}
					else{
						last_col = bin_maxis_i(cols,cols_size,0,cols_size-1,S/(rows[last_row]-rows[start_row])+cols[start_col]);
					}
				}
				tree_cnt = tree_prefix[last_row*cols_size+last_col];
				if(start_row>0){
					tree_cnt-=tree_prefix[(start_row-1)*cols_size+last_col];
				}
				if(start_col>0){
					tree_cnt-= tree_prefix[last_row*cols_size+start_col-1];
				}
				if(start_row>0 && start_col>0){
					tree_cnt += tree_prefix[(start_row-1)*cols_size+start_col-1];
				}
				if(tree_cnt > max){
					max = tree_cnt;
					lx = cols[start_col];
					ly = rows[start_row];
					rx = cols[last_col];
					ry = rows[last_row];
				}
				if(tree_cnt >= possible_trees){
					fprintf(fOut,"%d %d %d %d\n",lx,ly,rx,ry);
					return 0;
				}
				
			}
		}
	}
	fprintf(fOut,"%d %d %d %d\n",lx,ly,rx,ry);
}

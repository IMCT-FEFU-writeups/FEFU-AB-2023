#include <stdio.h>
#include <stdlib.h>

FILE *fIn, *fOut;

struct Attacks{
	int source;
	long long time;
};

struct LifeGifter{
	struct Attacks *attack;
	struct Attacks *defence;
	int attack_size, defence_size;
	int gang_cnt;
};

struct Request{
	int victim;
	long long time;
};

void addAttack(struct LifeGifter *gifter, long long time, int victim){
	if(gifter->attack_size==0){
		gifter->attack = calloc(10000,sizeof(struct Attacks));
		gifter->attack[gifter->attack_size].source = victim;
		gifter->attack[gifter->attack_size].time = time;
		(gifter->attack_size)++;
		return;
	}
	int flag = 0;
	for(int i = 0; i < gifter->attack_size-1; i++){
		if(gifter->attack[i].source == victim){
			flag = 1;
		}
		if(flag){
			gifter->attack[i] = gifter->attack[i+1];
		}
	}
	if(flag || gifter->attack_size>0 && gifter->attack[gifter->attack_size-1].source == victim){
	gifter->attack[gifter->attack_size-1].source = victim;
		gifter->attack[gifter->attack_size-1].time = time;
		return;
	}
	gifter->attack[gifter->attack_size].source = victim;
	gifter->attack[gifter->attack_size].time = time;
	(gifter->attack_size)++;
}

void addDefence(struct LifeGifter *gifter, long long time, int source){
	if(gifter->defence_size==0){
		gifter->defence = calloc(10000,sizeof(struct Attacks));
		gifter->defence[gifter->defence_size].source = source;
		gifter->defence[gifter->defence_size].time = time;
		(gifter->defence_size)++;
		return;
	}
	int flag = 0;
	for(int i = 0; i < gifter->defence_size-1; i++){
		if(gifter->defence[i].source == source){
			flag = 1;
		}
		if(flag){
			gifter->defence[i] = gifter->defence[i+1];
		}
	}
	if(flag || gifter->defence_size>0 && gifter->defence[gifter->defence_size-1].source == source){
		gifter->defence[gifter->defence_size-1].source = source;
		gifter->defence[gifter->defence_size-1].time = time;
		return;
	}
	gifter->defence[gifter->defence_size].source = source;
	gifter->defence[gifter->defence_size].time = time;
	(gifter->defence_size)++;
}

int first_index_defence(struct LifeGifter *gifter, long long time){
	int index = gifter->defence_size;
	int mul = 2;
	while(index/mul>0){
		if(gifter->defence[index - index/mul].time>=time){
			index-=index/mul;
		}
		mul*=2;
	}
	
	while(index<gifter->defence_size && gifter->defence[index].time<time){
		index++;
	}
	
	while(index>0 && gifter->defence[index-1].time>=time){
		index--;
	}
	return index;
	
}

int first_index_attack(struct LifeGifter *gifter, long long time){
	int index = gifter->attack_size;
	int mul = 2;
	while(index/mul>0){
		if(gifter->attack[index - index/mul].time>=time){
			index-=index/mul;
		}
		mul*=2;
	}
	
	while(index<gifter->attack_size && gifter->attack[index].time<time){
		index++;
	}
	
	while(index>0 && gifter->attack[index-1].time>=time){
		index--;
	}
	return index;
	
}

int attack_or_attacked_by_else(struct LifeGifter *gifter, int except, long long time){
	for(int index = first_index_defence(gifter,time); index < gifter->defence_size;index++){
		if(gifter->defence[index].source != except){
			return 1;
		}
	}
	for(int index = first_index_attack(gifter,time); index < gifter->attack_size;index++){
		if(gifter->attack[index].source != except){
			return 1;
		}
	}
	return 0;
}

void request(struct Request *request, struct LifeGifter *life_gifters, long long time){
	struct LifeGifter *victim = &life_gifters[request->victim-1];
	int first_index = first_index_defence(victim,time);
	for(int index = first_index_attack(victim,time); index < victim->attack_size;index++){
		int found = 0;
		for(int index1 = first_index; index1 < victim->defence_size;index1++){
			if(victim->attack[index].source == victim->defence[index1].source){
				found = 1;
				break;
			}
		}
		if(!found){
			return;
		}
	}
	
	for(int index = first_index; index < victim->defence_size;index++){
		struct LifeGifter *attacker = &life_gifters[victim->defence[index].source-1];
		if(attack_or_attacked_by_else(attacker,request->victim,time)){
			return;
		}
	}
	for(int index = first_index; index < victim->defence_size;index++){
		struct LifeGifter *attacker = &life_gifters[victim->defence[index].source-1];
		attacker->gang_cnt++;
	}
}

void step(struct LifeGifter *life_gifters, long long T, int flag){
	static struct Request *pool;
	static int pool_size;

  //initialize request pool
	if(pool == NULL){
		pool = calloc(10,sizeof(struct Request));
		pool_size == 0;
	}

  //read next log
	extern FILE *fIn;
	long long t;
	int a,v,r;
	fscanf(fIn,"%lld %d %d %d",&t,&a,&v,&r);

  //if log time change: flush request pool
	if(pool_size>0 && pool[pool_size-1].time < t){
		for(int i = 0; i < pool_size; i++){
			request(&pool[i],life_gifters,pool[i].time-T+1);
		}
		pool_size = 0;
	}

  //add new log to players
	addAttack(&life_gifters[a-1],t,v);
	addDefence(&life_gifters[v-1],t,a);

  //if it's the last log and here is no kill: flush request pool
	if(r == 0 && flag){
		for(int i = 0; i < pool_size; i++){
			request(&pool[i],life_gifters,pool[i].time-T+1);
		}
		pool_size = 0;
	}
  
  //if here is no kill: finish this log
	if(r == 0){
		return;
	}

  //create new pool request
	pool[pool_size].victim = v;
	pool[pool_size].time = t;
	pool_size++;

  //if is't the last log: flush pool request
	if(flag){
		for(int i = 0; i < pool_size; i++){
			request(&pool[i],life_gifters,pool[i].time-T+1);
		}
		pool_size = 0;
	}
}

int main() {
	extern FILE *fIn, *fOut;
	fIn = fopen("input.txt","r");
	fOut = fopen("output.txt","w");
	int N;
	long long T;
	fscanf(fIn,"%d %lld",&N, &T);
	struct LifeGifter *life_gifters = calloc(10,sizeof(struct LifeGifter));
	
	for(int i = 0; i < N; i++){
		step(life_gifters,T, i==N-1);
	}
	
	for(struct LifeGifter *gifter = life_gifters; gifter < life_gifters + 10; gifter++){
		fprintf(fOut,"%d ", gifter->gang_cnt);
	}
}

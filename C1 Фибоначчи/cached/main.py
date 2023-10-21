print("""
#include <stdio.h>

int main() {
    FILE* fin = fopen("input.txt", "r");
    FILE* fout = fopen("output.txt", "w+");
    int n;
    fscanf(fin, "%d", &n);
""")
d = [0, 1]
while len(d) < 100:
    d.append(d[-1] + d[-2])
prev_1, prev = 0, 1
now = 0
for i in range(95):
    now = prev + prev_1
    print("""
    if (n == """ + str(i) + """) {
        return 0;
    }
    fprintf(fout,  \"""" + str(d[i])+ """ \");
          """)
    prev_1 = prev
    prev = now
print("""
    return 0;
}
      """)

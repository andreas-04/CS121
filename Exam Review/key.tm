<TeXmacs|2.1.1>

<style|generic>

<\body>
  <section|>

  <\enumerate-Alpha>
    <item>

    <\enumerate-numeric>
      <item>F

      <item>F

      <item>F

      <item>F

      <item>T
    </enumerate-numeric>

    <item>

    <\enumerate-numeric>
      <item>

      <\cpp-code>
        int ret_sum(int[] int_arr, int size){

        \ \ \ \ \ \ \ \ int sum = 0;

        \ \ \ \ \ \ \ \ for(int i = 0; i \<less\> size; i++){

        \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ if(int_arr[n] % 2 == 0){

        \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ sum += int_arr[n];

        \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ }

        \ \ \ \ \ \ \ \ }

        \ \ \ \ \ \ \ \ return sum;

        }
      </cpp-code>

      <item>

      <\cpp-code>
        int ret_length(node* head){

        \ \ \ \ \ \ \ \ node* aux = head;

        \ \ \ \ \ \ \ \ int length;

        \ \ \ \ \ \ \ \ while(aux != NULL){

        \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ length++;

        \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ aux = aux-\<gtr\>next;

        \ \ \ \ \ \ \ \ }

        }
      </cpp-code>

      <item>

      <\cpp-code>
        char[] reverse_char_arr(char[] string){

        \ \ \ \ \ \ \ \ stack\<char\> myStack;

        \ \ \ \ \ \ \ \ int index = 0;

        \ \ \ \ \ \ \ \ while(string[index] != '\\0'){

        \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ myStack.push(string[index])

        \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ index++;

        \ \ \ \ \ \ \ \ }

        \ \ \ \ \ \ \ \ int new_index = 0;

        \ \ \ \ \ \ \ \ char[index] = new_arr;

        \ \ \ \ \ \ \ \ while(index != 0){

        \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ new_arr[new_index] = myStack.pop();

        \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ index--;

        \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ new_index++;

        \ \ \ \ \ \ \ \ }

        \ \ \ \ \ \ \ \ return new_arr;

        }
      </cpp-code>

      <item>

      skipped

      <item>

      <\cpp-code>
        tree_node* find_min(tree_node* root){

        \ \ \ \ \ \ \ \ if(root != NULL){

        \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ if(root-\<gtr\>left_child == NULL){

        \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ return
        root-\<gtr\>data;

        \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ }else

        \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ find_min(root-\<gtr\>left_child);

        \ \ \ \ \ \ \ \ }

        \ \ \ \ \ \ \ \ 

        }

        \;
      </cpp-code>
    </enumerate-numeric>

    <\enumerate-numeric>
      \;
    </enumerate-numeric>
  </enumerate-Alpha>

  <section|>

  <\enumerate-Alpha>
    <item>

    <\enumerate-numeric>
      <item>T

      <item>
    </enumerate-numeric>
  </enumerate-Alpha>
</body>

<\initial>
  <\collection>
    <associate|page-medium|paper>
  </collection>
</initial>

<\references>
  <\collection>
    <associate|auto-1|<tuple|1|1>>
    <associate|auto-2|<tuple|2|?>>
  </collection>
</references>

<\auxiliary>
  <\collection>
    <\associate|toc>
      <vspace*|1fn><with|font-series|<quote|bold>|math-font-series|<quote|bold>|1<space|2spc>>
      <datoms|<macro|x|<repeat|<arg|x>|<with|font-series|medium|<with|font-size|1|<space|0.2fn>.<space|0.2fn>>>>>|<htab|5mm>>
      <no-break><pageref|auto-1><vspace|0.5fn>
    </associate>
  </collection>
</auxiliary>
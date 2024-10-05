# [cpp 코딩테스트] 시간복잡도

- 시간복잡도란?
    - 수학적 정의 : Let M be a deterministic Turing machine that halts on all inputs. The *running time* or time complexity of M is the function $f : N \rightarrow N,$  where $f(n)$  is the maximum number of steps that $M$ uses on any input of length $n$.
        
        From "Introduction to the Theory of Computation” 
        
        → 해석 : 인풋 사이즈가 n일 때 주어진 계산을 하는데 있어서 필요한 계산량 중 최댓값은?
        
- 어떤 시간복잡도 표현이 있는가?
    - 다른 표기법들 : big O, small o, big theta, big omega, small omega가 있습니다.
        
        big O와 small o만 설명하겠습니다. omega는 O와 부등식을 반대로 적용하면 되고, theta는 상한, 하한이 각각 big O, big Omega로 존재하는 경우입니다. 
        
        - big O
        
        계산해야 하는 알고리즘이 $f(n)$인데, $f(n) = O(g(n))$를 만족한다면, Let $c>0$. $\exists n_0\in  N$  such that $\forall n\geq n_0$ , $f(n_0 ) \leq c g(n)$. 를 만족해야 합니다. 이것이 big-O notation의 수학적인 내용입니다. 간단히 정리하면 특정값부터 g(n)가 f(n)의 상한이 된다는 뜻입니다. 
        
        - small O
        
        small o는 big o의 정의에서 c가 모든 양수에 대해서 성립해야 하는 더 강한 조건입니다. 
        
        이는 small omega도 마찬가지입니다. 
        
        - big O, $f(n) = O(g(n))$ :
        - small o, $f(n) = o(g(n))$ :
        - big Theta, $f(n) = \Theta(g(n))$   :
        - big Omega, $f(n) = \Omega(g(n))$ :
        - small omega, $f(n) = \omega(g(n))$ :
    - 이렇게 다양한 표현법이 존재하는 이유는 시간복잡도가 특정 케이스에 따라 달라지는 경우가 있기 때문입니다.
        
         c++ vector에서 원소를 지우는 remove의 최악의 경우 $O(n)$입니다. 그러나, 맨뒤 원소만 지우는 pop_back();을 할 경우에는 
        
    
- big O - 계산방식 (or 사고방식)
    
    크게 big-O notation을 쓰게 됩니다. 그런데, $f(n) = O(n^2+n+1)$ $=O(n^2)$입니다. 이는 정확하게 말하면, 연산량이 같다가 아니라 $\approx$ 의 의미인 거의 비슷하다. 의 뜻입니다.
    
- 시간복잡도만 따져도 되는가?
    
    빠른 알고리즘인가, 느린 알고리즘인가만을 따질 땐 상관없다고 생각합니다. 하지만, 위에 언급한 것처럼 worst case, average case, best case를 전부 고려해서 생각해야 한다고 생각합니다. 
    
    시간복잡도는 공간복잡도와 연결이 되어있는 경우가 많습니다. 궁극적으로는 알고리즘의 시간복잡도를 줄이기 위해 공간복잡도를 줄이는 테크닉을 토글링(Toggling)이라고 합니다. 뿐만 아니라, 같
    

1. 시간복잡도가 무엇인지 정의하고, 빅오 표기법에서 최악의 경우(worst-case)를 고려하는 이유에 대해 설명하세요. 실제 상황에서 최악의 경우 시간복잡도가 중요한 이유를 설명하세요.
    
    
    시간복잡도는 앞서 말했듯이 주어진 인풋에 대해서 최대 얼마나 연산을 해야 하는지로 정의합니다. 최악의 경우를 고려하는 이유는 이 역시 앞서 말했듯이 얼마나 빠른지에 대해서는 최악의 경우엔 얼마나 느려지는지 따지는 것이 중요하기 때문입니다. 일단 그렇게 분류한 뒤에 같은 시간복잡도 분류끼리 디테일하게 얼마나 더 좋은 알고리즘인지 세세하게 논의하는 게 더 효율적입니다. 최악의 경우 시간복잡도가 중요한 경우는 이중연결리스트의 경우 첫번째와 원소를 제거할 때와 중간에 있는 원소를 제거할 때 걸리는 시간이 다릅니다. 이를 겨냥한 문제가 백준의 1406입니다. ( [https://www.acmicpc.net/problem/1406](https://www.acmicpc.net/problem/1406) ) 
    
2. 빅오 표기법을 사용하여 알고리즘의 효율성을 평가할 때 나타날 수 있는 한계점이나 오해는 무엇인지 설명하세요. 
    
    빅오는 알고리즘의 상한을 이야기를 합니다. 즉, 가장 최악의 케이스를 이야기를 한 겁니다. 방어적으로 모든 케이스에 대해서 생각할 땐 도움이 될 수 있지만, 그렇지 않고, 좋은 케이스만 나올 땐 그 알고리즘이 생각했던 것보다 더 빠를 수도 있습니다. 그러니 그런 오해를 하지 않으려면 worst, best, average를 전부 알고 있어야 합니다.

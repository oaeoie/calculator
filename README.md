# Todo
1. Seperate "expr" into "parse" and "calc"
2. Edit "parse" and "calc"

## parse
tokenize string by '+' sign -> '-' sign -> '*' sign -> '/' sign 
or

how tokenize?
1. 

### ex
1 + -2 * +3 + 4
(+ (1 + -2 * +3) (4))
(+ (+ (1) (-2 * +3)) (4))
(+ (+ (1) (* (-2) (+3))) (4))

## calc
easy implementation using function stacks

/*输入两个正整数 m 和 n，求它们的最大公约数和最小公倍数。

要求：

使用循环实现

至少有一种结果需要基于“最大公约数”推导

注意较大数和较小数的关系

示例输入：12 18

示例输出：

gcd = 6

       lcm = 36
*/

//不是很会写，故先抄答案
#include <stdio.h>

int main() {


}


//以下为参考
def calculate_gcd_lcm(m, n) :
    # 确保m为较大数，n为较小数
    if m < n:
m, n = n, m

# 使用辗转相除法求最大公约数
original_m, original_n = m, n
while n != 0:
m, n = n, m% n
gcd = m

# 基于最大公约数求最小公倍数
lcm = original_m * original_n // gcd
return gcd, lcm

# 主程序处理输入输出及异常情况
while True:
try :
    # 获取用户输入并转换为整数
    input_str = input("请输入两个正整数（用空格分隔）：")
    m, n = map(int, input_str.split())

    # 验证输入是否为正整数
    if m <= 0 or n <= 0:
print("输入错误：请确保输入的是正整数！")
continue

# 计算并输出结果
gcd, lcm = calculate_gcd_lcm(m, n)
print(f"gcd = {gcd}")
print(f"lcm = {lcm}")
break
except ValueError :
print("输入错误：请确保输入两个有效的整数并用空格分隔！")
except Exception as e :
print(f"发生错误：{e}")

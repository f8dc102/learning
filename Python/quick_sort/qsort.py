# 퀵 정렬 알고리즘 정의
def quick_sort(arr):
    if len(arr) <= 1:
        return arr
    pivot = arr[len(arr) // 2]
    left = [x for x in arr if x < pivot]
    middle = [x for x in arr if x == pivot]
    right = [x for x in arr if x > pivot]
    return quick_sort(left) + middle + quick_sort(right)


# input.txt 파일에서 데이터 읽기
with open("input.txt", "r") as file:
    data = file.read()

# 공백으로 구분된 정수들을 리스트로 변환
arr = list(map(int, data.split()))

# 퀵 정렬 적용
sorted_arr = quick_sort(arr)

# 결과 출력
print("정렬된 결과:", sorted_arr)

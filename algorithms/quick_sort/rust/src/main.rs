use std::fs::File;
use std::io::{self, BufRead};
use std::path::Path;

/// Quick Sort Partition Function
///
/// # Parameters
/// - `arr`: array to sort
/// - `low`: start index
/// - `high`: end index
///
/// # Returns
/// - pivot index
///
fn partition(arr: &mut [i32], low: isize, high: isize) -> isize {
    let pivot = arr[high as usize];
    let mut i = low - 1;

    for j in low..high {
        if arr[j as usize] < pivot {
            i += 1;
            arr.swap(i as usize, j as usize);
        }
    }
    arr.swap((i + 1) as usize, high as usize);
    i + 1
}

// 퀵 정렬 함수
fn quick_sort(arr: &mut [i32], low: isize, high: isize) {
    if low < high {
        let pi = partition(arr, low, high);
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

fn main() -> io::Result<()> {
    // 실행 시간
    let start = std::time::Instant::now();

    let path = "input.txt";
    let mut data: Vec<i32> = Vec::new();

    // 파일 열기
    if let Ok(lines) = read_lines(path) {
        // 파일에서 정수 읽기
        for line in lines {
            if let Ok(line) = line {
                let numbers = line.split_whitespace();
                for num in numbers {
                    if let Ok(value) = num.parse::<i32>() {
                        data.push(value);
                    }
                }
            }
        }
    }

    // 퀵 정렬 실행
    let len = data.len();
    if len > 0 {
        quick_sort(&mut data, 0, (len - 1) as isize);
    }

    // 실행 시간
    let end = std::time::Instant::now();

    // 정렬된 결과 출력
    println!("Sorted data: {:?}", data);

    // 실행 시간 출력
    println!("Execution Time: {}ms", (end - start).as_millis());

    Ok(())
}

// 파일을 줄 단위로 읽는 헬퍼 함수
fn read_lines<P>(filename: P) -> io::Result<io::Lines<io::BufReader<File>>>
where
    P: AsRef<Path>,
{
    let file = File::open(filename)?;
    Ok(io::BufReader::new(file).lines())
}

fn main() {
    // #세도잉, #가변성, #파라미터, #리턴, #소유권
    println!(
        "무언가 복잡해! 근데 많은 것을 배울 수 있지! 값은 {}야.",
        another_function("햅삐켓", 3)
    );

    println!("제어문 테스트: {:?}", ctrl_expressions(1, 2, 3));
}

fn another_function(name: &str, age: u32) -> i32 {
    println!("함수 호출! 다음 파라미터를 가지고: {}, {}", name, age);

    // 리턴 값은 세미콜론을 붙이지 않는다.
    own_test(age as i32)
}

fn own_test(x: i32) -> i32 {
    // x는 소유권을 가지고 있지만, y는 x의 값을 빌려온다.
    let y = x;
    // x는 이미 소유권을 잃었기 때문에 사용할 수 없다.
    // println!("{}", x);
    // y는 x의 값을 빌려왔기 때문에 사용할 수 있다.
    println!("{}", y);
    // y는 x의 값을 복사했기 때문에 y를 반환해도 된다.
    y
}

fn ctrl_expressions(x: i32, y: i32, z: i32) -> i32 {
    // 세 값중 가장 큰 값을 찾는다.
    let max: i32 = if x > y && x > z {
        x
    } else if y > x && y > z {
        y
    } else {
        z
    };

    let mut counter: i32 = max;

    loop {
        counter += 1;

        if counter == 10 {
            break counter * 2;
        }
    }
}

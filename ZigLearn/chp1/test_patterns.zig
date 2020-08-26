
const expect = @import("std").testing.expect;

test "some statements" {
    var some_variable: i32 = 5;
    const some_constant: u64 = 5000;

    var some_other_variable = @as(i32, 5);
    const some_other_constant = @as(u64, 5000);

    var x: u8 = undefined;
    const y: i16 = undefined;

    _ = 10;

    const a = [3]u8 { 1, 2, 3 };
    const other_a = [_]u8 { 1, 2, 3 };

    expect(1 == 1);
}


test "if statement" {
    const a = true;
    var x: u16 = 0;
    if (a) {
        x += 1;
    } else  {
        x += 2;
    }
    expect(x == 1);
}

test "if statement expression" {
    const a = true;
    var x: u16 = 0;
    x += if (a) 1 else 2;
    expect(x == 1);
}


test "while" {
    var i: u8 = 2;
    while (i < 100) {
        i *= 2;
    }
    expect(i == 128);
}


test "while with continue expression" {
    var sum: u8 = 0;
    var i: u8 = 1;
    while (i <= 10) : (i += 1) {
        sum += i;
    }
    expect(sum == 55);
}

test "while with continue" {
    var sum: u8 = 0;
    var i: u8 = 0;
    while (i <= 3) : (i += 1) {
        if (i == 2) continue;
        sum += i;
    }
    expect(sum == 4);
}

test "while with a break" {
    var sum: u8 = 0;
    var i: u8 = 0;
    while (i <= 3) : (i += 1) {
        if (i == 2) break;
        sum += i;
    }
    expect(sum == 1);
}

test "for" {
    //character literals are equivalent to integer literals
    const string = [_]u8{'a', 'b', 'c'};

    for (string) |character, index| {}

    for (string) |character| {}

    for (string) |_, index| {}

    for (string) |_| {}
}

fn addFive(x: u32) u32 {
    return x + 5;
}

test "function" {
    const y = addFive(0);
    expect(@TypeOf(y) == u32);
    expect(y == 5);
}

fn fibonacci(n: u16) u16 {
    if (n == 0 or n == 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

test "function recursion" {
    const x = fibonacci(10);
    expect(x == 55);
}

test "defer" {
    var x: u16 = 5;
    {
        defer x += 2;
        expect(x == 5);
    }
    expect(x == 7);
}

test "multi defer" {
    var x: f32 = 5;
    {
        defer x += 2;
        defer x /= 2;
    }
    expect(x == 4.5);
}

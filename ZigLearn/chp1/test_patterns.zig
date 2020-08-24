
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



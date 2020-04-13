open Jest;
open Expect;
open! Expect.Operators;
open Master;
open Keybol;
open Action;

describe("Expect", () =>
  test("toBe", () =>
    expect(1 + 2) |> toBe(3)
  )
);

describe("Expect.Operators", () =>
  test("==", () =>
    expect(1 + 2) === 3
  )
);

describe("keyToKeybol", () => {
  test("j key", () =>
    keyToKeybol("j") |> expect |> toEqual(J)
  );

  test("x key", () =>
    keyToKeybol("x") |> expect |> toEqual(UDKey("x"))
  );
});

describe("Dgt", () => {
  test({j|symbolize ["3", "9", "1"]|j}, () =>
    ["3", "9", "1"]
    |> List.map(keyToKeybol)
    |> expect
    |> toEqual([Dgt(D3), Dgt(D9), Dgt(D1)])
  );

  test({j|numerize ["3", "9", "1"]|j}, () =>
    ["3", "9", "1"]
    |> List.map(keyToKeybol)
    |> Shifu.numerizeKeybol
    |> expect
    |> toEqual(391)
  );
});

describe("instruction", () => {
  open Instruction;

  test({j|["j", "x"]|j}, () =>
    ["j", "x"]
    |> instruction
    |> expect
    |> toEqual({
         actions: [Move({horizontal: 0, vertical: (-1)})],
         keybab: [J],
         feedback: MsgFeedback("x is undefined"),
         nextAvailables: [J, ...allDigitKeybols],
       })
  );

  test({j|["j", "x", "j", "j"]|j}, () =>
    ["j", "x", "j", "j"]
    |> instruction
    |> expect
    |> toEqual({
         actions: [
           Move({horizontal: 0, vertical: (-1)}),
           Move({horizontal: 0, vertical: (-1)}),
           Move({horizontal: 0, vertical: (-1)}),
         ],
         keybab: [J, J, J],
         feedback: NoFeedback,
         nextAvailables: [J, ...allDigitKeybols],
       })
  );
});

open Jest;
open Expect;
open! Expect.Operators;

open Master.Instruction;
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

describe("instruction", () => {
  test({j|["j", "x"]|j}, () =>
    ["j", "x"]
    |> instruction
    |> expect
    |> toEqual({
         actions: [Move({horizontal: 0, vertical: (-1)})],
         keybab: [J],
         feedback: MsgFeedback("x is undefined"),
         nextAvailables: [J, ...digits],
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
         nextAvailables: [J, ...digits],
       })
  );
});

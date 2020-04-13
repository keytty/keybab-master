open Jest;
open Expect;
open! Expect.Operators;

open Keybab.Instruction;
open Command;
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

describe("keyToCommand", () => {
  test("j key", () =>
    keyToCommand("j") |> expect |> toEqual(J)
  );

  test("x key", () =>
    keyToCommand("x") |> expect |> toEqual(UDKey("x"))
  );
});

describe("instruction", () => {
  test({j|["j", "x"]|j}, () =>
    ["j", "x"]
    |> instruction
    |> expect
    |> toEqual({
         actions: [Move({horizontal: 0, vertical: (-1)})],
         commands: [J],
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
         commands: [J, J, J],
         feedback: NoFeedback,
         nextAvailables: [J, ...digits],
       })
  );
});

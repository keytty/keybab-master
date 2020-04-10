open Jest;
open Expect;
open! Expect.Operators;

open Keybab;
open Keybab.Command;
open Keybab.Action;

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

describe("instruction", () =>
  test({j|["j", "x"]|j}, () =>
    ["j", "x"]
    |> instruction
    |> expect
    |> toEqual({
         actions: [{type_: Move}],
         commands: [J],
         feedback: MsgFeedback("x is undefined"),
         nextAvailables: [J],
       })
  )
);

open Jest;
open Expect;
open! Expect.Operators;

open Keybab;

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

describe("instruction", () => {
  test("j key", () =>
    keyToCommand("j") |> expect |> toEqual(J)
  );

  test("x key", () =>
    keyToCommand("x") |> expect |> toEqual(UDKey("x"))
  );

  test({j|["j", "x"]|j}, () =>
    ["j", "x"]
    |> List.map(keyToCommand)
    |> instruction
    |> expect
    |> toEqual({
         actions: [{type_: Move}],
         commands: [J],
         feedback: Feedback("x is undefined"),
         nextAvailable: [J],
       })
  );
});

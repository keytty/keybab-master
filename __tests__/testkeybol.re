open Jest;
open Expect;
open! Expect.Operators;
open Keybol;

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
    |> Shifu.numerizeKeybab
    |> expect
    |> toEqual(391)
  );
});

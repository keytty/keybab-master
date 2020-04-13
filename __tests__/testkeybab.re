open Jest;
open Expect;
open! Expect.Operators;
open Keybol;

describe("tidy", () => {
  open Mariekondo;

  test("cacheEval 0", () =>
    (
      {
        looseDigits: [],
        drawerH: [],
        drawerJ: [],
        drawerK: [],
        drawerL: [],
        lastSymbol: None,
      }: cache
    )
    |> evaluateCache
    |> expect
    |> toEqual([])
  );

  test("cacheEval 1", () =>
    (
      {
        looseDigits: [Dgt(D2), Dgt(D3)],
        drawerH: [],
        drawerJ: [],
        drawerK: [],
        drawerL: [],
        lastSymbol: Some(Dgt(D3)),
      }: cache
    )
    |> evaluateCache
    |> expect
    |> toEqual([Dgt(D2), Dgt(D3)])
  );
});

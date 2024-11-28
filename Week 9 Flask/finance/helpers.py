import os
import requests
import urllib.parse

from flask import redirect, render_template, request, session
from functools import wraps


def apology(message, code=400):
    """Render message as an apology to user."""
    def escape(s):
        """
        Escape special characters.

        https://github.com/jacebrowning/memegen#special-characters
        """
        for old, new in [("-", "--"), (" ", "-"), ("_", "__"), ("?", "~q"),
                         ("%", "~p"), ("#", "~h"), ("/", "~s"), ("\"", "''")]:
            s = s.replace(old, new)
        return s
    return render_template("apology.html", top=code, bottom=escape(message)), code


def login_required(f):
    """
    Decorate routes to require login.

    https://flask.palletsprojects.com/en/1.1.x/patterns/viewdecorators/
    """
    @wraps(f)
    def decorated_function(*args, **kwargs):
        if session.get("user_id") is None:
            return redirect("/login")
        return f(*args, **kwargs)
    return decorated_function


def lookup(symbol):
    """Look up quote for symbol using Finnhub API."""
    try:
        api_key = os.environ.get("ct25919r01qoprggvqi0ct25919r01qoprggvqig")
        url = f"https://finnhub.io/api/v1/quote?symbol={urllib.parse.quote_plus(symbol)}&token={"ct25919r01qoprggvqi0ct25919r01qoprggvqig"}"
        response = requests.get(url)
        response.raise_for_status()
    except requests.RequestException as e:
        print(f"API request error: {e}")
        return None

    try:
        quote = response.json()
        if not quote or "c" not in quote or quote["c"] is None:
            return None
        return {
            "name": symbol,
            "price": float(quote["c"]),
            "symbol": symbol
        }
    except (KeyError, TypeError, ValueError) as e:
        print(f"Error parsing API response: {e}")
        return None



def usd(value):
    """Format value as USD."""
    return f"${value:,.2f}"
